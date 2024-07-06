#include "form.hpp"
using namespace std;
void hideCursor()
{
    cout << "\033[?25l";
}
int main()
{
    hideCursor();
    remove("bill.txt");
    Form loginForm;
    loginForm.showFormMenu();
    return 0;
}