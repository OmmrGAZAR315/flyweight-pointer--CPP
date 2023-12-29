#include <iostream>
#include <array>
#include <vector>

using namespace std;

//class Bullet {
//public:
//    string name;
//    double damage;
//    string weapon;
//    double x;
//    double y;
//
//    Bullet(string name, double damage, string weapon, double x, double y) :
//            name(std::move(name)), damage(damage), weapon(std::move(weapon)), x(x), y(y) {}
//
//};
class BulletType {
public:
    string name;
    double damage{};
    string weapon;

    BulletType() = default;

    BulletType(const string &name, double damage, const string &weapon) : name(name), damage(damage), weapon(weapon) {}

};

class Bullet {
public:
    double x;
    double y;
    string type;
    BulletType bulletType;


    Bullet(double x, double y, string type, string const &name, double damage, string const &weapon) {
        this->x = x;
        this->y = y;
        this->type = std::move(type);
        this->bulletType = BulletFactory::getBulletType(name, damage, weapon);
    }

    class BulletFactory {
    public:
        static std::vector<BulletType> bullets;

        static BulletType getBulletType(string name, double damage, string weapon) {
            for (const auto &bullet: bullets) {
                if (bullet.name == name)
                    return bullet;
            }
            return bullets.emplace_back(name, damage, weapon);
        }
    };


    static void draw() {
        cout << "Bullet" << endl;
    }

};

int main() {
    array<Bullet, 4> bullets = {
            Bullet(0, 0, "pistol", "pistol", 10, "pistol"),
            Bullet(0, 0, "pistol", "pistol", 10, "pistol"),
            Bullet(0, 0, "pistol", "pistol", 10, "pistol"),
            Bullet(0, 0, "pistol", "pistol", 10, "pistol")
    };
    Bullet x = bullets[0];
    cout << sizeof(x) << endl;
    cout << sizeof(bullets) << endl;
    return 0;
}