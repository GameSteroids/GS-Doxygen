namespace Geometry {
    //!  Class representing 2D Vectors.
    class Vector2 {
    public:
        /**
        *  @brief Default constructor. 
        *  Components are not guaranteed to be zero.
        *  @see Copy
        */ 
        Vector2();
        /// Copy constructor of the vector
        Vector2(Vector2 &v);
        /// Default constructor, takes 2 axis
        Vector2(float x, float y);
        /// sum operator.
        Vector2 operator +(Vector2 v);
        /// subtraction operator.
        Vector2 operator -(Vector2 v);
        /// scaling operator.
        Vector2 operator *(float s);
        /// equality operator.
        bool operator ==(Vector2 v);
        /// division operator.
        Vector2 operator /(float s);
        /// returns the x axis.
        float x;
        /// returns the y axis.
        float y;
        /**
        *  @brief Copy from object
        *  @param o the object to copy
        *  Copies from generic other object that matches a basic vector (has attribute x and y or [1] and [2])
        *  @code Vector2.Copy{1,1} == Vector2(1,1) @endcode
        */
        static Vector2 Copy(object o);
        /// @return self
        Vector2 To2D();
        /// @return Vector3(x, 0, y) 
        Vector3 To3D();
        /// @return Vector4(x, 0, y, 0)
        Vector4 To4D();
        /// @return table representation
        table ToTable();
        /// @return integer point representation (multiplied by 10^x)
        Point ToPoint(int x = 0);
        /**
        *  @brief getter of the length
        */
        float Length();
        /**
        *  @brief distance to another vector
        *  Same as: (self - other):Length()
        *  @see Length()
        */
        float DistanceTo(Vector2 other);
        /**
        *  @brief Returns a point in Barycentric coordinates, using the specified vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205485(v=vs.85).aspx
        */
        Vector2 BaryCentric(Vector2 v2, Vector2 v3, float f, float g);
        /**
        *  @brief Performs a Catmull-Rom interpolation, using the specified vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205506(v=vs.85).aspx
        */
        Vector2 CatmullRom(Vector2 v1, Vector2 v2, Vector3 v3, float s);
        /**
        *  @brief Returns the z-component by taking the cross product of two vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205486(v=vs.85).aspx
        */
        float CCW(Vector2 v2);
        /**
        *  @brief checks if counterclockwise
        *  @return > 0 if counterclockwise oriented, <0 if clockwise
        */
        float CCW(Vector2 v2, Vector2 v3);
        /**
        *  @brief Determines the dot product of two vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205488(v=vs.85).aspx
        */
        float Dot(Vector2 v2);
        /**
        *  @brief Performs a Hermite spline interpolation, using the specified vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205489(v=vs.85).aspx
        */
        Vector2 Hermite(Vector2 t1, Vector2 v2, Vector2 t2, float s);
        /**
        *  @brief Performs a linear interpolation between two vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205492(v=vs.85).aspx
        */
        Vector2 Lerp(Vector2 v2, float s);
        /**
        *  @brief Returns a vector that is made up of the largest components of two vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205493(v=vs.85).aspx
        */
        Vector2 Maximize(Vector2 v2);
        /**
        *  @brief Returns a vector that is made up of the smallest components of two vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205494(v=vs.85).aspx
        */
        Vector2 Minimize(Vector2 v2);
        /**
        *  @brief Returns the normalized version of a vector.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205495(v=vs.85).aspx
        */
        Vector2 Normalize();
        /**
        *  @brief Transforms a vector by a given matrix.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205498(v=vs.85).aspx
        */
        Vector4 Transform(Matrix4 m);
        /**
        * @brief Transforms a vector by a given matrix, projecting the result back into w = 1.
        * @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205500(v=vs.85).aspx
        */
        Vector2 TransformCoord(Matrix4 m);
        /**
        * @brief Transforms the vector normal by the given matrix.
        * @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205502(v=vs.85).aspx
        */
        Vector2 TransformNormal(Matrix4 m);
        /**
        *  @brief Scales a vector.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205496(v=vs.85).aspx
        */
        Vector2 Scale(float s);
        /**
        *  @brief returns the unpacked attributes of a vector
        */
        x y unpack();
        /**
        *  @brief Returns the perpendicular 'cross' vector
        */
        Vector2 Cross();
        /**
        *  @brief Returns the z-component by taking the cross product of two vectors.
        *  @see CCW
        */
        float Cross(Vector2 vs);
        /**
        *  @brief Returns the closest point to the line (infinite)
        *  @param a point on line
        *  @param b point on line
        *  @see ProjectOnLineSegment
        *  @return the point on the line
        *  @return a bool that tells if the point is in between point a and b
        */
        Vector2 bool ProjectOnLine(Vector2 a, Vector2 b);
        /**
        *  @brief Returns the closest point to the line segment
        *  @param a startpoint of line segment
        *  @param b endpoint of line segment
        *  @see ProjectOnLine
        *  @return the point on the line segment
        *  @return a bool that tells if the point is equals the point from ProjectOnLine
        */
        Vector2 bool ProjectOnLineSegment(Vector2 a, Vector2 b);
        /**
        *  @brief Calculates interception points of moving target and particle with linear speed
        *  @param self startpoint of target
        *  @param endPoint destination of target
        *  @param speedTarget velocity of target
        *  @param sourcePos emitter of particle
        *  @param sourceSpeed speed of particle in u/s
        *  @param delay (optional) delay of particle in seconds
        *  @return time and positions of collision
        */
        t1 p1 t2 p2 Interception(Vector2 endPoint, float speedTarget, Vector2 sourcePos, float sourceSpeed, float delay = 0);
        /**
        *  @brief Calculates the intersection of two lines (infinite)
        *  @param self start of first line
        *  @param v2 end of first line
        *  @param v3 start of second line
        *  @param v4 end of second line
        *  @return the intersection point or nil
        */
        Vector2 Intersection(Vector2 v2, Vector2 v3, Vector2 v4);
        /**
        *  @brief Checks if two line segments intersect
        *  may not be accurate in edge cases such as two lines on top of each other
        *  @param self start of first line
        *  @param v2 end of first line
        *  @param v3 start of second line
        *  @param v4 end of second line
        *  @return true if line segments intersect, false otherwise
        */
        bool IsIntersection(Vector2 v2, Vector2 v3, Vector2 v4);
        /**
        *  @brief Checks if the Vector lies on a line segment.
        */
        bool IsPartOfLineSegment(Vector2 v1, Vector2 v2);
        /**
        *  @brief Gets the relative angle to the second vector using the origin
        *  @return the angle in rad
        */
        double Angle(Vector2 v2 = {0, 0});
        /**
        *  @brief Gets the relative angle to the second vector using the origin
        *  @return the angle in degree
        */
        double AngleDeg(Vector2 v2 = {0, 0});
        /**
        *  Rotates the vector clockwise
        *  @param s angle in rad
        */
        Vector2 Rotate(float s);
        /**
        *  Rotates the vector clockwise
        *  @param s angle in degree
        */
        Vector2 RotateDeg(float s);
    };

    //!  Class representing 3D Vectors.
    class Vector3 {
    public:
        /**
        *  @brief Default constructor. 
        *  Components are not guaranteed to be zero.
        *  @see Copy
        */ 
        Vector3();
        /// Copy constructor of the vector
        Vector3(Vector3 &v);
        /// Default constructor, takes 2 axis
        Vector3(float x, float y, float z);
        /// sum operator.
        Vector3 operator +(Vector3 v);
        /// substraction operator.
        Vector3 operator -(Vector3 v);
        /// scaling operator.
        Vector3 operator *(float s);
        /// equality operator.
        bool operator ==(Vector3 v);
        /// division operator.
        Vector3 operator /(float s);
        /// returns the x axis.
        float x;
        /// returns the y axis.
        float y;
        /// returns the z axis.
        float z;
        /**
        *  @brief Copy from object
        *  @param object
        *  Copies from generic other object that matches a basic vector (has attribute x,y and z or [1],[2] and [3])
        *  @code Vector3.Copy{1,2,3} == Vector2(1,2,3) @endcode
        */
        static Vector3 Copy(object o);
        /// @return Vector2(x, z)
        Vector2 To2D();
        /// @return self 
        Vector3 To3D();
        /// @return Vector4(x, y, z, 0)
        Vector4 To4D();
        /// @return table representation
        table ToTable();
        /**
        *  @brief getter of the length
        */
        float Length();
        /**
        *  @brief distance to another vector
        *  Same as: (self - other):Length()
        *  @see Length()
        */
        float DistanceTo(Vector3 other);
        /**
        *  @brief Returns a point in Barycentric coordinates, using the specified vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205505(v=vs.85).aspx
        */
        Vector3 BaryCentric(Vector3 v2, Vector3 v3, float f, float g);
        /**
        *  @brief Performs a Catmull-Rom interpolation, using the specified vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205506(v=vs.85).aspx
        */
        Vector3 CatmullRom(Vector3 v1, Vector3 v2, Vector3 v3, float s);
        /**
        *  @brief checks if counterclockwise (in topdown 2D)
        *  @return > 0 if counterclockwise oriented, <0 if clockwise
        */
        float CCW(Vector3 v2, Vector3 v3);
        /**
        *  @brief Determines the dot product of two vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205508(v=vs.85).aspx
        */
        float Dot(Vector3 v2);
        /**
        *  @brief Performs a Hermite spline interpolation, using the specified vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205509(v=vs.85).aspx
        */
        Vector3 Hermite(Vector3 t1, Vector3 v2, Vector3 t2, float s);
        /**
        *  @brief Performs a linear interpolation between two vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205512(v=vs.85).aspx
        */
        Vector3 Lerp(Vector3 v2, float s);
        /**
        *  @brief Returns a vector that is made up of the largest components of two vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205513(v=vs.85).aspx
        */
        Vector3 Maximize(Vector3 v2);
        /**
        *  @brief Returns a vector that is made up of the smallest components of two vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205514(v=vs.85).aspx
        */
        Vector3 Minimize(Vector3 v2);
        /**
        *  @brief Returns the normalized version of a vector.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205515(v=vs.85).aspx
        */
        Vector3 Normalize();
        /**
        *  @brief Transforms a vector by a given matrix.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205520(v=vs.85).aspx
        */
        Vector4 Transform(Matrix4 m);
        /**
        * @brief Transforms a vector by a given matrix, projecting the result back into w = 1.
        * @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205522(v=vs.85).aspx
        */
        Vector3 TransformCoord(Matrix4 m);
        /**
        * @brief Transforms the vector normal by the given matrix.
        * @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205524(v=vs.85).aspx
        */
        Vector3 TransformNormal(Matrix4 m);
        /**
        *  @brief Scales a vector.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205518(v=vs.85).aspx
        */
        Vector3 Scale(float s);
        /**
        *  @brief returns the unpacked attributes of a vector
        */
        x y z unpack();
        /**
        *  @brief Determines the cross-product of two vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205507(v=vs.85).aspx
        */
        float Cross(Vector3 v2);
        /**
        *  @brief Projects a 3D vector from object space into screen space.
        *  !Currently impossible to use!
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205516(v=vs.85).aspx
        */
        Vector3 Project(...);
        /**
        *  @brief Projects a vector from screen space into object space.
        *  !Currently impossible to use!
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205526(v=vs.85).aspx
        */
        Vector3 Unproject(...);
    };

    //!  Class representing 4D Vectors.
    class Vector4 {
    public:
        /**
        *  @brief Default constructor. 
        *  Components are not guaranteed to be zero.
        *  @see Copy
        */ 
        Vector4();
        /// Copy constructor of the vector
        Vector4(Vector4 &v);
        /// Default constructor, takes 2 axis
        Vector4(float x, float y, float z, float w);
        /// sum operator.
        Vector4 operator +(Vector4 v);
        /// substraction operator.
        Vector4 operator -(Vector4 v);
        /// scaling operator.
        Vector4 operator *(float s);
        /// equality operator.
        bool operator ==(Vector4 v);
        /// division operator.
        Vector4 operator /(float s);
        /// returns the x axis.
        float x;
        /// returns the y axis.
        float y;
        /// returns the z axis.
        float z;
        /// returns the w axis.
        float w;
        /**
        *  @brief Copy from object
        *  @param object
        *  Copies from generic other object that matches a basic vector (has attribute x,y,z,w or [1],..[4])
        *  @code Vector4.Copy{1,2,3,4} == Vector4(1,2,3,4) @endcode
        */
        static Vector4 Copy(object o);
        /// @return Vector2(x, z)
        Vector2 To2D();
        /// @return Vector3(x, y, z) 
        Vector3 To3D();
        /// @return self
        Vector4 To4D();
        /// @return table representation
        table ToTable();
        /**
        *  @brief getter of the length
        */
        float Length();
        /**
        *  @brief distance to another vector
        *  Same as: (self - other):Length()
        *  @see Length()
        */
        float DistanceTo(Vector4 other);
        /**
        *  @brief Returns a point in Barycentric coordinates, using the specified vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205529(v=vs.85).aspx
        */
        Vector4 BaryCentric(Vector4 v2, Vector4 v3, float f, float g);
        /**
        *  @brief Performs a Catmull-Rom interpolation, using the specified vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205530(v=vs.85).aspx
        */
        Vector4 CatmullRom(Vector4 v1, Vector4 v2, Vector4 v3, float s);
        /**
        *  @brief Determines the dot product of two vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205532(v=vs.85).aspx
        */
        float Dot(Vector4 v2);
        /**
        *  @brief Performs a Hermite spline interpolation, using the specified vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205533(v=vs.85).aspx
        */
        Vector4 Hermite(Vector4 t1, Vector4 v2, Vector4 t2, float s);
        /**
        *  @brief Performs a linear interpolation between two vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205536(v=vs.85).aspx
        */
        Vector4 Lerp(Vector4 v2, float s);
        /**
        *  @brief Returns a vector that is made up of the largest components of two vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205537(v=vs.85).aspx
        */
        Vector4 Maximize(Vector4 v2);
        /**
        *  @brief Returns a vector that is made up of the smallest components of two vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205538(v=vs.85).aspx
        */
        Vector4 Minimize(Vector4 v2);
        /**
        *  @brief Returns the normalized version of a vector.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205515(v=vs.85).aspx
        */
        Vector4 Normalize();
        /**
        *  @brief Transforms a vector by a given matrix.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205542(v=vs.85).aspx
        */
        Vector4 Transform(Matrix4 m);
        /**
        *  @brief Scales a vector.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205540(v=vs.85).aspx
        */
        Vector4 Scale(float s);
        /**
        *  @brief returns the unpacked attributes of a vector
        */
        x y z w unpack();
        /**
        *  @brief Determines the cross-product of two vectors.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205531(v=vs.85).aspx
        */
        float Cross(Vector4 v2);
    };

    /**
*  @brief Class representing a 4x4 Matrix
*  @see http://msdn.microsoft.com/de-de/library/windows/desktop/bb172912(v=vs.85).aspx
*/
    class Matrix4 {
    public:
        /**
        *  @brief Default constructor. 
        *  Components are not guaranteed to be zero.
        *  @see Copy
        */        
        Matrix4();
        /// Copy constructor of the vector
        Matrix4(Matrix4 &v);
        /// sum operator.
        Matrix4 operator +(Matrix4 v);
        /// substraction operator.
        Matrix4 operator -(Matrix4 v);
        /// scaling operator.
        Matrix4 operator *(float s);
        /// transform operator.
        Matrix4 operator *(Matrix4 s);
        /// equality operator.
        bool operator ==(Matrix4 v);
        /// division operator.
        Matrix4 operator /(float s);
        /// (1,1) component
        float _11;
        /// (1,2) component
        float _12;
        /// (1,3) component
        float _13;
        /// (1,4) component
        float _14;
        /// (2,1) component
        float _21;
        /// (2,2) component
        float _22;
        /// (2,3) component
        float _23;
        /// (2,4) component
        float _24;
        /// (3,1) component
        float _31;
        /// (3,2) component
        float _32;
        /// (3,3) component
        float _33;
        /// (3,4) component
        float _34;
        /// (4,1) component
        float _41;
        /// (4,2) component
        float _42;
        /// (4,3) component
        float _43;
        /// (4,4) component
        float _44;
        ///is true if matrix is identity matrix
        bool isIdentity;
        /**
        *  @brief Copy from object
        *  @param object
        *  Copies from generic other object that matches a 4x4 Matrix (has attribute _11, _12.. or [1],..[16])
        *  @code Matrix4.Copy{1,2,3,4,...} @endcode
        */
        static Matrix4 Copy(object o);
        /**
        *  @brief Builds a 3D affine transformation matrix. NULL arguments are treated as identity transformations.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb172914(v=vs.85).aspx
        */
        static Matrix4 AffineTransformation(float Scaling, Vector3 RotationCenter, Quaternion Rotation, Vector3 Translation);
        /**
        *  @brief Builds a 2D affine transformation matrix in the xy plane. NULL arguments are treated as identity transformations.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205336(v=vs.85).aspx
        */
        static Matrix4 AffineTransformation2D(float Scaling, Vector2 RotationCenter, float Rotation, Vector2 Translation);
        /**
        *  @brief Creates an identity matrix.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205339(v=vs.85).aspx
        */
        static Matrix4 Identity();
        /**
        *  @brief Builds a left-handed, look-at matrix.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205342(v=vs.85).aspx
        */
        static Matrix4 LookAtLH(Vector3 Eye, Vector3 At, Vector3 Up);
        /**
        *  @brief Builds a right-handed, look-at matrix.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205343(v=vs.85).aspx
        */
        static Matrix4 LookAtRH(Vector3 Eye, Vector3 At, Vector3 Up);
        /**
        *  @brief Builds a left-handed orthographic projection matrix.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205346(v=vs.85).aspx
        */
        static Matrix4 OrthoLH(float w, float h, float zn, float zf);
        /**
        * @brief Builds a right-handed orthographic projection matrix.
        * @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205349(v=vs.85).aspx
        */
        static Matrix4 OrthoRH(float w, float h, float zn, float zf);
        /**
        *  @brief Builds a customized, left-handed orthographic projection matrix.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205347(v=vs.85).aspx
        */
        static Matrix4 OrthoOffCenterLH(float l, float r, float b, float t, float zn, float zf);
        /**
        *  @brief Builds a customized, right-handed orthographic projection matrix.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205348(v=vs.85).aspx
        */
        static Matrix4 OrthoOffCenterRH(float l, float r, float b, float t, float zn, float zf);
        /**
        *  @brief Builds a left-handed perspective projection matrix based on a field of view.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205350(v=vs.85).aspx
        */
        static Matrix4 PerspectiveFovLH(float fovy, float Aspect, float zn, float zf);
        /**
        *  @brief Builds a right-handed perspective projection matrix based on a field of view.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205351(v=vs.85).aspx
        */
        static Matrix4 PerspectiveFovRH(float fovy, float Aspect, float zn, float zf);
        /**
        *  @brief Builds a left-handed perspective projection matrix
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205352(v=vs.85).aspx
        */
        static Matrix4 PerspectiveLH(float w, float h, float zn, float zf);
        /**
        *  @brief Builds a right-handed perspective projection matrix
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205352(v=vs.85).aspx
        */
        static Matrix4 PerspectiveRH(float w, float h, float zn, float zf);
        /**
        *  @brief Builds a customized, left-handed perspective projection matrix.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205353(v=vs.85).aspx
        */
        static Matrix4 PerspectiveOffCenterLH(float l, float r, float b, float t, float zn, float zf);
        /**
        *  @brief Builds a customized, right-handed perspective projection matrix.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205354(v=vs.85).aspx
        */
        static Matrix4 PerspectiveOffCenterRH(float l, float r, float b, float t, float zn, float zf);
        /**
        *  @brief Builds a matrix that reflects the coordinate system about a plane.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205356(v=vs.85).aspx
        */
        static Matrix4 Reflect(Vector4 Plane);
        /**
        *  @brief Builds a matrix that rotates around an arbitrary axis.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205357(v=vs.85).aspx
        */
        static Matrix4 RotationAxis(Vector3 V, float Angle);
        /**
        *  @brief Builds a rotation matrix from a quaternion.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205358(v=vs.85).aspx
        */
        static Matrix4 RotationQuaternion(Quaternion Q);
        /**
        *  @brief Builds a matrix that rotates around the x-axis.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205359(v=vs.85).aspx
        */
        static Matrix4 RotationX(float Angle);
        /**
        *  @brief Builds a matrix that rotates around the y-axis.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205360(v=vs.85).aspx
        */
        static Matrix4 RotationY(float Angle);
        /**
        *  @brief Builds a matrix that rotates around the z-axis.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205362(v=vs.85).aspx
        */
        static Matrix4 RotationZ(float Angle);
        /**
        *  @brief Builds a matrix with a specified yaw, pitch, and roll.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205361(v=vs.85).aspx
        */
        static Matrix4 RotationYawPitchRoll(float Yaw, float Pitch, float Roll);
        /**
        *  @brief Builds a matrix that scales along the x-axis, the y-axis, and the z-axis.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205363(v=vs.85).aspx
        */
        static Matrix4 Scaling(float sx, float sy, float sz);
        /**
        *  @brief Builds a matrix that flattens geometry into a plane.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205364(v=vs.85).aspx
        */
        static Matrix4 Shadow(Vector4 Light, Vector4 Plane);
        /**
        *  @brief Builds a transformation matrix. nil arguments are treated as identity transformations.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205365(v=vs.85).aspx
        */
        static Matrix4 Transformation(Vector3 ScalingCenter, Quaternion ScalingRotation, Vector3 Scaling, Vector3 RotationCenter, Quaternion Rotation, Vector3 Translation);
        /**
        *  @brief Builds a 2D transformation matrix that represents transformations in the xy plane. nil arguments are treated as identity transformations.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205366(v=vs.85).aspx
        */
        static Matrix4 Transformation2D(Vector2 ScalingCenter, float ScalingRotation, Vector2 Scaling, Vector2 RotationCenter, float Rotation, Vector2 Translation);
        /**
        *  @brief Builds a matrix using the specified offsets.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205367(v=vs.85).aspx
        */
        static Matrix4 Translation(float x, float y, float z);
        /**
        *  @brief Zero based access of row and column component
        *  @code
        *  Matrix4 m = Matrix4.Identity() 
        *  m._11 = 10 
        *  assert(m._11 == m:At(0,0)) 
        *  @endcode
        */
        float At(int row, int colummn);
        /**
        *  @brief Breaks down a general 3D transformation matrix into its scalar, rotational, and translational components.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205337(v=vs.85).aspx
        */
        Scale Rotation Translation Decompose();
        /**
        *  @brief Returns the determinant of a matrix.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205338(v=vs.85).aspx
        */
        float Determinant();
        /**
        *  @brief Calculates the inverse of a matrix.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205340(v=vs.85).aspx
        */
        Matrix4 Inverse();
        /**
        *  @brief Calculates the transposed product of two matrices.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205345(v=vs.85).aspx
        */
        Matrix4 MultiplyTranspose();
        /**
        *  @brief Returns the matrix transpose of a matrix.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205368(v=vs.85).aspx
        */
        Matrix4 Transpose();
    };

    //!  Class representing Quaternions.
    class Quaternion {
    public:
        /**
        *  @brief Default constructor. 
        *  Components are not guaranteed to be zero.
        *  @see Copy
        */   
        Quaternion();
        /// Copy constructor of the vector
        Quaternion(Quaternion &v);
        /// Default constructor, takes 2 axis
        Quaternion(float x, float y, float z, float w);
        /// sum operator.
        Quaternion operator +(Quaternion v);
        /// substraction operator.
        Quaternion operator -(Quaternion v);
        /// scaling operator.
        Quaternion operator *(float s);
        /// equality operator.
        bool operator ==(Quaternion v);
        /// division operator.
        Quaternion operator /(float s);
        /// returns the x axis.
        float x;
        /// returns the y axis.
        float y;
        /// returns the z axis.
        float z;
        /// returns the w axis.
        float w;
        /**
        *  @brief Copy from object
        *  @param object
        *  Copies from generic other object that matches a basic vector (has attribute x,y,z,w or [1],..[4])
        *  @code Vector4.Copy{1,2,3,4} == Vector4(1,2,3,4) @endcode
        */        
        static Quaternion Copy(object o);
        /**
        *  @brief Returns the identity quaternion.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205407(v=vs.85).aspx
        */
        static Quaternion Identity();
        /**
        *  @brief Rotates a quaternion about an arbitrary axis.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205415(v=vs.85).aspx
        */
        static Quaternion RotationAxis(Vector3 V, float Angle);
        /**
        *  @brief Builds a quaternion from a rotation matrix.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205416(v=vs.85).aspx
        */
        static Quaternion RotationMatrix(Matrix4 m);
        /**
        *  @brief Builds a quaternion with the given yaw, pitch, and roll.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205417(v=vs.85).aspx
        */
        static Quaternion RotationYawPitchRoll(float Yaw, float Pitch, float Roll);
        /**
        *  @brief Returns a quaternion in barycentric coordinates.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205403(v=vs.85).aspx
        */
        Quaternion BaryCentric(Quaternion Q2, Quaternion Q3, float f, float g);
        /**
        *  @brief Returns the conjugate of a quaternion.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205404(v=vs.85).aspx
        */
        Quaternion Conjugate();
        /**
        *  @brief Returns the dot product of two quaternions.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205405(v=vs.85).aspx
        */
        float Dot(Quaternion Q2);
        /**
        *  @brief Calculates the exponential.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205406(v=vs.85).aspx
        */
        Quaternion Exp();
        /**
        *  @brief Conjugates and renormalizes a quaternion.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205408(v=vs.85).aspx
        */
        Quaternion Inverse();
        /**
        *  @brief Returns the length of a quaternion.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205410(v=vs.85).aspx
        */
        float Length();
        /**
        *  @brief Returns the distance to another quaternion
        *  @see Length
        */
        float DistanceTo();
        /**
        *  @brief Calculates the natural logarithm.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205412(v=vs.85).aspx
        */
        Quaternion Ln();
        /**
        *  @brief Computes a unit length quaternion.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205414(v=vs.85).aspx
        */
        Quaternion Normalize();
        /**
        *  @brief Interpolates between two quaternions, using spherical linear interpolation.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205418(v=vs.85).aspx
        */
        Quaternion Slerp(Quaternion Q2, float t);
        /**
        *  @brief Interpolates between quaternions, using spherical quadrangle interpolation.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205419(v=vs.85).aspx
        */
        Quaternion Squad(Quaternion A, Quaternion B, Quaternion C, float t);
        /**
        *  @brief Sets up control points for spherical quadrangle interpolation.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205420(v=vs.85).aspx
        */
        A B C SquadSetup(Quaternion Q1, Quaternion Q2, Quaternion Q3);
        /**
        *  @brief Computes a quaternion's axis and angle of rotation.
        *  @see http://msdn.microsoft.com/en-us/library/windows/desktop/bb205421(v=vs.85).aspx
        */
        Axis Angle ToAxisAngle();
    };
    
    //!  Class representing a rectangle
    class Rect {
    public:
        /// Default constructor 
        Rect();
        /// copies the rectangle
        Rect(Rect &v) {
        }
        /// Creates Rect object
        Rect(float left, float top, float right, float bottom) {
        }
        /// returns the left position.
        float left;
        /// returns the top position.
        float top;
        /// returns the right position.
        float right;
        /// returns the bottom position.
        float bottom;
        /// returns the left position
        float x;
        /// returns the top position
        float y;
        /// gets and sets the unfixed! width
        float width;
        /// gets and sets the unfixed! height
        float height;
        
    };
    
    //!  Class representing a 2D integer point
    class Point {
    public:
        ///Default constructor
        Point();
        /// copies the rectangle
        Point(Point &v);
        /// Creates Point object
        Point(int x, int y);
        /// returns the x position.
        int x;
        /// returns the y position
        int y;
        /// returns false if outside polygon, +1 if inside and -1 if point is on polygon boundary
        bool IsInside(Polygon poly);
        /// converts the point to a Vector2 (floating point) (multiplied by 10^x)
        Vector2 ToVector(int x = 0);
    };
    
    //! Class representing a 2D Polygon (Array of Point). Clipper name: Path
    class Polygon {
    public: 
        ///Default constructor
        Polygon();
        ///Copy constructor
        Polygon(Polygon &);
        ///Constructor that constructs a specific amount of points
        Polygon(int size);
        /**
        *  Constructs an empty Polygon and reserves space for x amount of points (does not add any points)
        */
        static Polygon Reserve(int x);
        /**
            *  the size of the polygon with #
            *  @code
            *  for i = 1, #poly do
            *      print(poly:Get(i))
            *  end
            *  @endcode
            */
        __len();
        /**
            *  @brief Draws the outline of the Polygon
            */
        void DrawOutline(float width, Graphics.Color color);
        /**
            *  @brief the iterator of the points
            *  @code
            *  for point in poly.children do
            *      print(point)
            *  end
            *  @endcode
            */
        iterator children;
        /**
            *  @brief the orientation of the polygon
            *  @see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Functions/Orientation.htm
            */
        bool orientation;
        /**
            *  @brief the area of the polygon
            *  @see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Functions/Area.htm
            */
        double area;
        /**
            *  @brief the minkowski sum of the polygon
            *  @param self the polygon to calculate the Minkowski sum from
            *  @param pattern the pattern of the calculation
            *  @see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Functions/MinkowskiSum.htm
            */
        Polygons MinkowskiSum(Polygon pattern, bool pathIsClosed = true);
        /**
            *  @brief the minkowski difference between two polygons
            *  @param self the first polygon
            *  @param other the second polygon of the calculation 
            *  @see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Functions/MinkowskiDiff.htm
            */
        Polygons MinkowskiDiff(Polygon other, bool pathIsClosed = true);
        /**
            *  @brief Cleans the polygon
            *  @return self or nil if the cleaning failed
            *  @see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Functions/CleanPolygon.htm
            */
        Polygon Clean(double distance = 1.45);
        /**
            *  @brief Gets a reference to a point in the polygon-array.
            */
        Point& Get(int index);
        /**
            *  @brief Sets a Point inside the polygon-array
            */
        void Set(int index, Point value);
        /**
            *  @brief Adds a Point to the polygon (multiplied by 10^m)
            */
        void Add(int x, int y, int m = 0);
        /**
        *  @brief Adds a Vector2 to the polygon (multiplied by 10^m)
        */
        void Add(Vector2 p, int m = 0);
        /**
        *  @brief Adds a Point to the polygon
        */
        void Add(Point p);
        /**
            *  @brief Adds the points (Point/Vector2) inside the list to the polygon (multiplied by 10^m)
            */
        void Add(table t, int m = 0);
        /**
        *  @brief Clears every point from the polygon
        */
        void Clear();
        /**
            *  @brief Simplifies the polygon
            *  @see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Functions/SimplifyPolygon.htm
            */
        Polygons Simplify(Clipper.PolyFillType fill = Clipper.EVEN_ODD);
        /**
            *  @brief Reverses the polygon vertex order
            *  @see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Functions/ReversePath.htm
            */
        void Reverse();
    };
    
    //! Class representing 2D Polygons (Array of Polygon). Clipper name: Paths
    class Polygons {
    public:
        ///Default constructor
        Polygons();
        ///Copy constructor
        Polygons(Polygons &);
        ///Constructor that constructs a specific amount of empty polygons
        Polygons(int size);
        /**
        *  Constructs an empty Polygon list and reserves space for x amount of polygons (does not add any polygon)
        */
        static Polygons Reserve(int x);
        /**
            *  the size of the polygon with #
            *  @code
            *  for i = 1, #poly do
            *      print(poly:Get(i))
            *  end
            *  @endcode
            */
        __len();
        /**
            *  @brief Draws the outline of the Polygons
            */
        void DrawOutline(float width, Graphics.Color color);
        /**
            *  @brief the iterator of the points
            *  @code
            *  for polygon in polys.children do
            *      print(polygon)
            *  end
            *  @endcode
            */
        iterator children;
        /**
            *  @brief the minkowski sum of the polygons
            *  @param self the polygons to calculate the Minkowski sum from
            *  @param pattern the pattern of the calculation
            *  @see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Functions/MinkowskiSum.htm
            */
        Polygons MinkowskiSum(Polygon pattern, bool pathIsClosed = true);
        /**
            *  @brief Cleans the polygons
            *  @return self or nil if the cleaning failed
            *  @see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Functions/CleanPolygons.htm
            */
        Polygons Clean(double distance = 1.45);
        /**
            *  @brief Gets a reference to a polygon in the polygons-array.
            */
        Polygon& Get(int index);
        /**
            *  @brief Sets a polygon inside the polygons-array
            */
        void Set(int index, Polygon value);
        /**
            *  @brief Adds a polygon to the polygons
            */
        void Add(Polygon p);
        /**
            *  @brief Adds the polygon(s) inside the list to the polygon list
            */
        void Add(table t);
        /**
            *  @brief Simplifies the polygons
            *  @return self or nil if the simplification failed
            *  @see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Functions/SimplifyPolygons.htm
            */
        Polygons Simplify(Clipper.PolyFillType fill = Clipper.EVEN_ODD);
        /**
            *  @brief Reverses the polygon vertex order of the polygons
            *  @see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Functions/ReversePaths.htm
            */
        void Reverse();
        /**
            *  @brief Offsets the polygons
            *  @see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Functions/OffsetPaths.htm
            */
        Polygons Offset(double delta, Clipper.JoinType jointype, Clipper.EndType endType, double miter_limit);
    };

    //! Class for Polygon operations
    class Clipper {
    public:
        typedef int PolyType;
        const PolyType CLIP;
        const PolyType SUBJECT;
        typedef int PolyFillType;
        const PolyFillType EVEN_ODD;
        const PolyFillType NON_ZERO;
        const PolyFillType POSITIVE;
        const PolyFillType NEGATIVE;
        typedef int ClipType;
        const ClipType INTERSECTION;
        const ClipType UNION;
        const ClipType DIFFERENCE;
        const ClipType XOR;
        typedef int JoinType;
        const JoinType JOIN_MITER;
        const JoinType JOIN_ROUND;
        const JoinType JOIN_SQUARE;
        typedef int EndType;
        const EndType END_BUTT;
        const EndType END_CLOSED;
        const EndType END_ROUND;
        const EndType END_SQUARE;
        typedef int InitOptions;
        const InitOptions REVERSE_SOLUTION;
        const InitOptions STRICTLY_SIMPLE;
        const InitOptions PRESERVE_COLLINEAR;
        ///Default constructor
        Clipper();
        ///Constructor takes options
        Clipper(InitOptions options);
        ///Bounding Box of the contained polygons
        Geometry.Rect bounds;
        ///@see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Classes/Clipper/Properties/StrictlySimple.htm
        bool strictlySimple;
        ///@see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Classes/Clipper/Properties/ReverseSolution.htm
        bool reverseSolution;
        ///@see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Classes/Clipper/Properties/PreserveCollinear.htm
        bool preserveCollinear;
        ///@see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Classes/Clipper/Methods/Execute.htm
        Polygons Execute(Clipper &clipper, ClipType clipType, PolyFillType subjFillType = EVEN_ODD, PolyFillType clipFillType = EVEN_ODD);
        ///Clears all added polygons
        ///@see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Classes/ClipperBase/Methods/Clear.htm
        void Clear();
        /**
        *  Adds a Polygon using PolyType SUBJECT
        *  @see AddPolygon
        */
        void AddSubject(Polygon poly, bool isPathClosed = true);
        /**
        *  Adds Polygons using PolyType SUBJECT
        *  @see AddPolygons
        */
        void AddSubject(Polygons polys, bool isPathClosed = true);
        /**
        *  Adds a Polygon using PolyType CLIP
        *  @see AddPolygon
        */
        void AddClip(Polygon poly, bool isPathClosed = true);
        /**
        *  Adds Polygons using PolyType CLIP
        *  @see AddPolygons
        */
        void AddClip(Polygons polys, bool isPathClosed = true);
        /**
        *  @brief Adds a single polygon
        *  @see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Classes/ClipperBase/Methods/AddPath.htm
        */
        void AddPolygon(Polygon poly, PolyType PolyTyp, bool Closed);
        /**
        *  @brief Adds multiple polygons
        *  @see http://www.angusj.com/delphi/clipper/documentation/Docs/Units/ClipperLib/Classes/ClipperBase/Methods/AddPaths.htm
        */
        void AddPolygons(Polygons polys, PolyType PolyTyp, bool Closed);
    };  
}