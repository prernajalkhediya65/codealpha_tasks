
#include <iostream>
using namespace std;
class findgrade
{
    float q1, q2, qt, midmarks, finalmarks;
    float percentage, percq, percM, percF;
    string grade;

public:
    void getmarks();
    void calcmarks();
    void calcgrade();
    void showgrade();
} obj;

int main()
{

    obj.getmarks();
    obj.calcmarks();
    obj.calcgrade();
    obj.showgrade();

    return 0;
}
void findgrade ::getmarks()
{
    cout << "enter obtained marks of quiz #1 out of (10) ::";
    cin >> q1;
    cout << "enter obtained marks of quiz #2 out of (10) ::";
    cin >> q2;
    cout << "enter obtained marks of mid term #3 out of (100) ::";
    cin >> midmarks;
    cout << "enter obtained marks of final term #4 out of (100) ::";
    cin >> finalmarks;
    cout << endl;
}
void findgrade ::calcmarks()
{
    qt = q1 + q2;
    percq = (25.0 / 20.0) * qt;
    percM = (25.0 / 100.0) * midmarks;
    percF = (50.0 / 100.0) * finalmarks;
    percentage = percq + percM + percF;
}
void findgrade ::calcgrade()
{
    if (percentage >= 90.0)
        grade = 'A';

    if (percentage >= 80.0 && percentage < 90)
        grade = 'B';

    if (percentage >= 70.0 && percentage < 80)
        grade = 'C';

    if (percentage >= 60.0 && percentage < 70)
        grade = 'D';

    if (percentage >= 50.0 && percentage < 60)
        grade = 'E';

    if (percentage >= 40.0 && percentage < 30)
        grade = 'F';
}
void findgrade ::showgrade()
{
    cout << "\n\n";
    cout << "the obtained grade :" << grade << endl;
    cout << "---------------------------" << endl;
}