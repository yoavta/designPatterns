#include <vector>
#include <string>
#include <tuple>
#include <iostream>

class Buyer {
protected:
    int currenMoney;
    std::vector<std::string> property;
public:
    Buyer(int startMoney) {
        currenMoney = startMoney;
    }

    void buySomething(int cost, std::string name) {
        property.push_back(name);
        currenMoney -= cost;
    }

    void addMoney(int salary) {
        currenMoney += salary;
    }

    void printProperty() {
        int i = 0;
        for (; i < property.size(); i++) {
            std::cout << property[i] << std::endl;
        }
    }
};


class DollarsShop {
protected:
    std::vector<std::tuple<std::string, int>> products;
public:
    DollarsShop() {
        products.push_back(std::make_tuple("balloon", 5));
        products.push_back(std::make_tuple("home", 500));
        products.push_back(std::make_tuple("PC", 50));
    }

    virtual void printProducts() {
        int i = 0;
        std::cout<<"DOLLAR SHOP\n:";
        for (; i < products.size(); i++) {
            std::cout << std::get<0>(products[i]) << "- price: " << std::get<1>(products[i]) << " Dollars." << std::endl;
        }
        std::cout<<std::endl;

    }
};

class IlsShopAdapter : public DollarsShop {
protected:
    float DollarRate = 3.1;
public:
    virtual void printProducts() {
        int i = 0;
        std::cout<<"Ils SHOP:\n";
        for (; i < products.size(); i++) {
            std::cout << std::get<0>(products[i]) << "- price: " << int(std::get<1>(products[i]) * DollarRate) << " Ils."
                      << std::endl;
        }
        std::cout<<std::endl;

    }

};


int main() {
    Buyer *buyer = new Buyer(5000);
    DollarsShop *dollarsShop = new DollarsShop();
    buyer->printProperty();
    dollarsShop->printProducts();
    IlsShopAdapter *ilsShopAdapter = new IlsShopAdapter();
    ilsShopAdapter->printProducts();

    buyer->buySomething(15,"ballon");
    buyer->buySomething(155,"PC");
    buyer->printProperty();
    return 1;
}