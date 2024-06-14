#include <iostream>
#include <array>
#include <vector>

using namespace std;

class BulletType {
public:
    string name;
    double damage{};
    string weapon;

    BulletType() = default;

    BulletType(const string &name, double damage, const string &weapon) : name(name), damage(damage), weapon(weapon) {}

};

class BulletFactory {
public:
    static std::vector<BulletType> bullets;
    static int x;

    static BulletType &getBulletType(const string &name, double damage, const string &weapon) {
        for (const auto &bullet: bullets) {
            if (bullet.name == name)
                return const_cast<BulletType &>(bullet);
        }
        return bullets.emplace_back(name, damage, weapon);
    }
};

class Bullet {
public:
    string name;
    double damage;
    string weapon;
    double x;
    double y;

    Bullet(string name, double damage, string weapon, double x, double y) :
            name(std::move(name)), damage(damage), weapon(std::move(weapon)), x(x), y(y) {}

};

class Bullet2 {
public:
    double x;
    double y;
    string type;
    BulletType *bulletType;

    Bullet2(double x, double y, string type, string const &name, double damage, string const &weapon)
            : x(x), y(y), type(std::move(type)) {
        this->bulletType = &BulletFactory::getBulletType(name, damage, weapon);
    }

};

std::vector<BulletType> BulletFactory::bullets;

int main() {

    array<Bullet, 4> bullets = {
            Bullet("pistol", 10.45, "pistol", 10, 10),
            Bullet("pistol", 10.45, "pistol", 10, 10),
            Bullet("pistol", 10.45, "pistol", 10, 10),
            Bullet("pistol", 10.45, "pistol", 10, 10),
    };

    array<Bullet2, 4> bullets2 = {
            Bullet2(0, 0, "pistol", "pistol", 10, "pistol"),
            Bullet2(0, 0, "shotgun", "pistol", 10, "pistol"),
            Bullet2(0, 0, "pistol", "pistol", 10, "pistol"),
            Bullet2(0, 0, "pistol", "pistol", 10, "pistol"),
    };
    cout << ".....Flyweight Design Pattern.....\n\n";
    cout << "----Without using pointer in Bullet class\n";
    cout << "Size of one element " << sizeof(bullets[0]) << " Bytes" << endl;
    cout << "Size of all elements " << sizeof(bullets) << " Bytes\n" << endl;
    cout << "----With using pointer in Bullet class\n";
    cout << "Size of one element " << sizeof(bullets2[0]) << " Bytes" << endl;
    cout << "Size of all elements " << sizeof(bullets2) << " Bytes" << endl;
    return 0;
}