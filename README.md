# colorwin
colorwin is a small Windows C++ library under the MIT license that provides scoped coloring of console output.  A single header file with a simple API comprises the library.  The scoped aspect of the library expedites safely adding color to existing console projects.

# colorwin's scoped color control
Scoped coloring means that a colorwin object is created to change the console color and the color is reset back to the original color on destruction of that same object.  Thus, there is less chance of accidentally coloring output you don't mean to.  For example, if your project is using exceptions and using colorwin objects, an exception would reset the console color through C++'s automatic destruction of stack objects (C++ stack unwinding).  If you are adding console coloring to existing projects, you never have to worry about resetting the color back to normal; that means 1 change instead of 2 changes, meaning less opportunities for mistakes and omissions.

# Caveats
* Your console application should protect against multiple threads writing to the console concurrently.  In that case, colorwin should only be used within that protection.
* Dark colors are commented out in the color enumeration to discourage you from using them.  You may comment them in, but they are not very readable.
* Changing the background color is not enabled in colorwin.  Users change the default background color of the command prompt, and Powershell's background is blue by default.  Setting the text background color will result in filled rectangles around text.
