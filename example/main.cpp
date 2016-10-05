#// The MIT License(MIT)
// Copyright(c) 2016  Jeff Rebacz
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files(the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and / or sell copies
// of the Software, and to permit persons to whom the Software is furnished to do
// so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "..\src\colorwin.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace colorwin;

// Show text in each color.
void DemoAllColors()
{
    cout << color(white) << "DemoAllColors()\n";
    cout << color(red) << "red\n";
    cout << color(yellow) << "yellow\n";
    cout << color(green) << "green\n";
    cout << color(cyan) << "cyan\n";
    cout << color(blue) << "blue\n";
    cout << color(magenta) << "magenta\n";
    cout << color(white) << "white\n";
    cout << color(gray) << "gray\n";
    cout << color(grey) << "grey\n";
    cout << color(dark_gray) << "dark_gray\n";
    cout << color(dark_grey) << "dark_grey\n";
}

// Demonstrate that scoped colors revert to the original color
// if an exception is thrown "unexpectedly".
void DemoException()
{
    cout << color(white) << "DemoException()\n";
    try
    {
        cout << "This is the original text color.\n";
        withcolor scoped(cyan);
        cout << "Connection " << color(green) << "OK";
        cout << " attempting transfer.\n";
        throw exception("Connection lost"); //oops, I hope the console color doesn't remain cyan!
        cout << "Transfer completed.\n";
    }
    catch (exception &e)
    {
        cout << color(red) << "ERROR: " << e.what() << "\n";
        cout << "Transfer aborted.\n";
    }
    cout << "Text color is back to the original color.\n";
}

// Demonstrate multiple levels of scoped console colors.
void DemoScoped()
{
    cout << color(white) << "DemoScoped()\n";
    {
        withcolor scoped(red);
        cout << "|red\n";
        cout << "|red again\n";
        {
            withcolor scoped(yellow);
            cout << "||now yellow\n";
            {
                withcolor scoped(cyan);
                cout << "|||now cyan\n";
                withcolor(white).printf("|||| withcolor(white).printf(...)\n");
                printf("|||::printf cyan\n");

            }
        }
        cout << "|now back to red.\n";
    }
    cout << "now back to normal\n";
}

int main()
{
    using namespace std;
    using namespace colorwin;

    string separator(40, '=');

    cout << color(white) << separator << "\n";
    DemoAllColors();

    cout << "\n" << color(white) << separator << "\n";
    DemoException();

    cout << "\n" << color(white) << separator << "\n";
    DemoScoped();

    cout << "\n\nHit the enter key to exit.";
    cin.get();
    return 0;
}