This module provides a password component field for the Webform module.  It enables administrators to password protect webforms.

TODO
----

* Replace simple SHA1 hash encryption with the user_password_hash
* Use password confirm field type for webform component settings page
* Add option to store password in plain text

Installation
------------

* Copy the webform_password_component module to your modules directory.
* Enable the module

Usage
-----

* Create or a new webform or edit an existing webform.
* A new field component named `password` will be available in the dropdown.  Select this, name the field and hit add.
* Enter in a password in the settings page.  This is the same password users will need to enter from the webform view

Author
------
Desmond Morris
hi@desmondmorris.com
