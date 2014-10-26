
//!  class with WebView functions and structures
class WebView {
public:
    typedef int State;
    static const State NONE;
    static const State FAILED;
    static const State BEGIN;
    static const State READY;
    static const State FINISH;
    ///Gets the main WebView
	static WebView GetMain();    
    /**
	* Loads an url to the html overlay
	* @param url url to load
	* @see LoadHome()
	*/
	void LoadUrl(string url);
	/**
	* Loads the default overlay url
	* @see LoadUrl()
	*/
	void LoadHome();
    /**
	* Calls jQuery to get an object by ID
	* @param id html object ID
	*/
	object JQuery(string id);
    ///The window object
    JSObject window;
    ///Check if webview is loading
    bool loading;
    ///Gets an object from javascript
    JSObject GetObject(string name, string xpath = "");
    ///Creates a new object in javascript
    JSObject CreateObject(string name, string xpath = "");
    /**
     *  Used to interact with Javascript Objects.
     *  This object tries to synchronise itself with javascript
     */
	class JSObject {
	public:
		int id;
        /**
         *  Gets a property from the javascript object.
         *  Almost similar to jsobject.propertyName.
         */
        object GetProperty(string propertyName);
        /**
         *  Sets a property of a javascript object.
         *  Almost similar to jsobject.propertyName = property.
         */
        void SetProperty(string name, object value);
        /**
        * Invokes a javascript member function.
        * @param method member function to call in js
        * @note This function is synchronous. Use BeginInvoke if possible.
        * @note This function does not work with function arguments.
        */
        object Invoke(string method, args...);
        /**
         *  Invokes a javascript member function asynchronously.
         *  @param method the javascript member function to call
         *  @note This function does not work with function arguments.
         */
        void BeginInvoke(string method, args...);
	};
}