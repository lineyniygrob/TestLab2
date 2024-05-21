#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Базовый класс, представляющий товар
 * * \image html D:\test\test3\bes.bmp"
 * \f[
 * x_{1,2} = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}
 * \f]
 */
class Product {
protected:
    int id;         ///< Идентификатор товара
    string name;    ///< Название товара
    double price;   ///< Цена товара

public:
    /**
     * @brief Создает новый экземпляр класса Product
     * @param id Идентификатор товара
     * @param name Название товара
     * @param price Цена товара
     */
    Product(int id, const string& name, double price)
        : id(id), name(name), price(price) {}

    /**
     * @brief Выводит информацию о товаре
     */
    virtual void displayInfo() const {
        cout << "ID: " << id << endl;
        cout << "Название: " << name << endl;
        cout << "Цена: " << price << endl;
    }

    /**
     * @brief Возвращает информацию о товаре в виде строки
     * @return Строка с информацией о товаре
     */
    string getInfo() const {
        return "ID: " + to_string(id) + "\nНазвание: " + name + "\nЦена: " + to_string(price);
    }
};

/**
 * @brief Класс, представляющий электронный товар
 * @details Этот класс наследует класс Product и добавляет информацию о гарантийном периоде.
 */
class ElectronicProduct : public Product {
private:
    int warrantyPeriod;  ///< Гарантийный срок товара (в месяцах)

public:
    /**
     * @brief Создает новый экземпляр класса ElectronicProduct
     * @param id Идентификатор товара
     * @param name Название товара
     * @param price Цена товара
     * @param warrantyPeriod Гарантийный срок товара (в месяцах)
     */
    ElectronicProduct(int id, const string& name, double price, int warrantyPeriod)
        : Product(id, name, price), warrantyPeriod(warrantyPeriod) {}

    /**
     * @brief Выводит информацию об электронном товаре
     */
    void displayInfo() const override {
        Product::displayInfo();
        cout << "Гарантийный период: " << warrantyPeriod << " месяцев" << endl;
    }
};

/**
 * @brief Класс, представляющий книжный товар
 * @details Этот класс наследует класс Product и добавляет информацию об авторе книги.
 */
class BookProduct : public Product {
private:
    string author;  ///< Автор книги

public:
    /**
     * @brief Создает новый экземпляр класса BookProduct
     * @param id Идентификатор товара
     * @param name Название товара
     * @param price Цена товара
     * @param author Автор книги
     */
    BookProduct(int id, const string& name, double price, const string& author)
        : Product(id, name, price), author(author) {}

    /**
     * @brief Выводит информацию о книжном товаре
     */
    void displayInfo() const override {
        Product::displayInfo();
        cout << "Автор: " << author << endl;
    }
};

int main() {
    // Создание экземпляра электронного товара
    ElectronicProduct electronicProduct(1, "Электронный товар", 999.99, 12);

    // Создание экземпляра книжного товара
    BookProduct bookProduct(2, "Книжный товар", 19.99, "Автор");

    // Вывод информации о товарах
    electronicProduct.displayInfo();
    cout << endl;
    bookProduct.displayInfo();

    return 0;
}
