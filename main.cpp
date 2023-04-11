#include "iostream"
#include "ctime"
#include "src/app.h"

using namespace std;

int main()
{
    srand(time(0));
    App app = App();
    app.cicloPrincipal();
    return 0;
}
