#include <iostream>

using namespace std;

class Time{
private:
    int hour;
    int minute;
    int second;
public:
    Time(){

    }

    Time(int seconds){
        hour = seconds / 3600;
        minute = seconds % 3600 / 60;
        second = seconds % 60;
    }

    operator int() const {
        return hour * 3600 +
                minute * 60 +
                second;
    }

    Time operator-(Time &o){
        int s1 = hour * 3600 + minute * 60 + second,
            s2 = o.hour * 3600 + o.minute * 60 + o.second;
        Time t(s1 - s2);
        return t;
    }

    void setHour(int hours) {
        hour = hours;
    }

    void setMinute(int minutes){
        minute = minutes;
    }

    void setSecond(int seconds){
        second = seconds;
    }

    int getHour(){
        return hour;
    }

    int getMinute(){
        return minute;
    }

    int getSecond(){
        return second;
    }
};

istream& operator>> (istream& stream,  Time& t){
    char c;
    int hour{}, minute{}, second{};
    stream >> hour >> c>>c >> minute >> c>>c >> second >> c;

    t.setHour(hour);
    t.setMinute(minute);
    t.setSecond(second);

    return stream;
}

ostream & operator << (ostream &out, Time &t){
    // 10h:8m:41s
    if(t.getHour() != 0)
        out << t.getHour() << "h:";

    if(t.getMinute() < 10)
        out << "0";
    out << t.getMinute() << "m:";

    if(t.getSecond() < 10)
        cout << "0";
    out << t.getSecond() << "s";

    return out;
}

int main() {
    Time t1(200);
    cout << t1 << endl; // displays 03m:20s
    Time t2;
    cin >> t2; // user enters 10h:12m:01s

    cout << t2 << endl;

    Time t3 = t2 - t1; // 10h:8m:41s
    int t3s = t3; // 36521

    cout << t3s << endl;

    return 0;
}
