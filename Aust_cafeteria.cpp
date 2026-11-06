#include <iostream>
#include <string>
#include <vector>
#include<fstream>
using namespace std;

// class declaration
class menuItem //class declaration
{
private:
    
    int itemID;
    string itemName;
    double itemPrice;
    int stock; 

public:
    // Constructor
    menuItem(int id, string name, double price, int s)
    {
        itemID = id;
        itemName = name;
        itemPrice = price;
        stock = s; 
    }

   
    void disPlay()
    {
        cout << "Id no:" << itemID
             << " Name:" << itemName
             << " Price:" << itemPrice << "Taka"
             << " Item left  :" << stock <<"pcs"<< endl; 
    }

    
    int getItemID()
    {
        return itemID;
    }

    
    double getprice()
    {
        return itemPrice;
    }

    
    int getStock()
    {
        return stock;
    }

    
    void reduceStock(int quantity)
    {
        stock =stock- quantity;
    }

    
    string getItemName()
    {
        return itemName;
    }
};


// class  2 declaration 
class Canteen
{
private:
    //   store all available menu items.
    vector<menuItem> menu;

    // store the items selected by the customer.
    // CHANGED: now stores item + quantity
    vector<pair<menuItem, int>> order;

public:

    //for manager
    void addMenuItem(int ID, string NAME, double PRICE, int STOCK)
    {
        menu.push_back(menuItem(ID, NAME, PRICE, STOCK));
    }

    //  displays all the items currently available in the menu.
    void DisplayMenu()
    {
        // Check whether the menu is empty.
        if (menu.empty())
        {
            cout << "Menu is empty" << endl;
            return;
        }

        cout << "========AUST Cafeteria Menu ============" << endl;

        
        for (auto &item : menu)
        {
            item.disPlay();//to show menu vectors all elements 3 parts.
        }
    }
    

    
    void takeOrder()
    {
        int itemID;
        int quantity;

        // Ask the customer to enter the ID of the item.
        // when 0 is entered, 0 will finish the order taking .
        cout << "Enter Item Id to place an Order{Note:Click zero to Dismiss}: ";

        while (true)
        {
            cin >> itemID;

            // If the customer enters 0, stop taking the order.
            if (itemID == 0)
            {
                break;
            }

            //  check whether the entered item ID exists.
            bool found = false;

            
            for (auto &item : menu)
            {
                if (item.getItemID() == itemID)
                {
                    
                    
                    if (item.getStock() == 0)
                    {
                        cout << "OUT OF STOCK!!!" << endl;
                    }
                    else
                    {
                        cout << "Available Stock: " << item.getStock() << endl;
                        cout << "Enter Quantity: ";
                        cin >> quantity;

                        
                        if (quantity <= item.getStock() && quantity > 0)
                        {
                            
                            order.push_back({item, quantity});

                            item.reduceStock(quantity);
                        }
                        else
                        {
                            cout << "Not enough stock!!!" << endl;
                        }
                    }

                    found = true;
                    break;
                }
            }

            
            if (!found)
            {
                cout << "!!!!SOORRY, Item not found!!!" << endl;
            }
        }

        
        long double total = 0;

        cout << "=======Your Order Summary======" << endl;

       
        
        for (auto &orderItem : order)
        {
            cout << "Item Name: " << orderItem.first.getItemName()
                 << "    Quantity: " << orderItem.second << endl;

            
            total += orderItem.first.getprice() * orderItem.second;
        }

        
        cout << "Total Price: " << total << "/-" << endl;
        cout << "Order confirmed,show this to a waiter please!" << endl;
        cout << "Thank you for being with us." << endl;     

        //  file handling
        ofstream file("order.txt", ios::app);

        
        for (auto &orderItem : order)
        {
            file << "Item: " << orderItem.first.getItemName()
                 << " Quantity: " << orderItem.second
                 << " Price: " << orderItem.first.getprice() * orderItem.second
                 << endl;
        }

        file << "Total: " << total << "/-" << endl;
        file.close();

        order.clear();   
    }   
 
}; 
    


int main()
{     
    cout << "Hello Dear Student,Welcome to Ahsanullah University of Science and Technology Cafeteria";
    cout << endl;
     
    //object
    Canteen canteen;

    //Cafeteria manager can add or delete items.
    canteen.addMenuItem(1, "Burger", 50, 20);
    canteen.addMenuItem(2, "Dim Chop", 20, 30);
    canteen.addMenuItem(3, "Pizza", 70, 10);
    canteen.addMenuItem(4, "Somucha", 10, 50);
    canteen.addMenuItem(5, "Roll", 60, 20);
    canteen.addMenuItem(6, "Singara", 10, 50);
    canteen.addMenuItem(7, "Jilapee", 10, 30);
    canteen.addMenuItem(8, "Bel puri 6 pcs", 30, 20);
    canteen.addMenuItem(9, "Lemonade", 20, 30);
    canteen.addMenuItem(10, "Khichuri+dim", 70, 20);
    canteen.addMenuItem(11, "Polao+Chicken roast", 120, 15);
    canteen.addMenuItem(12, "Noodles", 30, 20);
    canteen.addMenuItem(13, "Dragon juice", 40, 20);
    canteen.addMenuItem(14, "Chicken chap", 120, 15);
    canteen.addMenuItem(15, "Khacchi biriyani", 250, 10);
    canteen.addMenuItem(16, "Dal", 20, 30);
    canteen.addMenuItem(17, "vaji", 20, 30);
    canteen.addMenuItem(18, "Porota 1 pcs",10, 50);
    canteen.addMenuItem(19, "Dal+Vaji mix", 20, 30);
    canteen.addMenuItem(20, "Fried rice+Vegetable+chicken", 120, 15);
    canteen.addMenuItem(1, "2 pcs Fried Chicken", 200, 47);
    canteen.addMenuItem(2, "2 pcs Fried Chicken Plus", 260, 32);
    canteen.addMenuItem(3, "3 pcs Fried Chicken Plus", 340, 58);
    canteen.addMenuItem(4, "5 pcs Fried Chicken", 460, 24);
    canteen.addMenuItem(5, "Chicken Drumstick", 310, 71);
    canteen.addMenuItem(6, "Chicken Nuggets (5 pcs)", 275, 43);
    canteen.addMenuItem(7, "Crispy Strips (4 pcs)", 270, 36);
    canteen.addMenuItem(8, "Chicken Wings", 230, 65);

    canteen.addMenuItem(9, "Single Chicken Broast (S/R)", 240, 29);
    canteen.addMenuItem(10, "Double Chicken Broast (S/R)", 400, 18);

    canteen.addMenuItem(11, "Chicken Chow mein", 280, 52);
    canteen.addMenuItem(12, "Vegetable Chow mein", 250, 41);

    canteen.addMenuItem(13, "Quarter Tandoori Chicken", 270, 27);
    canteen.addMenuItem(14, "Half Tandoori Chicken", 440, 34);
    canteen.addMenuItem(15, "Full Tandoori Chicken", 800, 15);
    canteen.addMenuItem(16, "Hot Tandoori Wings", 270, 48);

    canteen.addMenuItem(17, "Chicken Hariyali Kebab", 290, 39);
    canteen.addMenuItem(18, "Chicken Tikka Kebab", 290, 56);
    canteen.addMenuItem(19, "Beef Tikka Kebab", 400, 22);
    canteen.addMenuItem(20, "Chicken Reshmi Kebab", 290, 44);
    canteen.addMenuItem(21, "Chicken Shaslick Kebab", 300, 31);
    canteen.addMenuItem(22, "Beef Shaslick Kebab", 410, 19);
    canteen.addMenuItem(23, "Chicken Grill Donner Kebab", 320, 63);
    canteen.addMenuItem(24, "Beef Grill Donner Kebab", 410, 26);
    canteen.addMenuItem(25, "Fish Tikka Kebab", 330, 37);
    canteen.addMenuItem(26, "Fish Shaslick Kebab", 350, 28);
    canteen.addMenuItem(27, "Beef Shik Kebab", 260, 45);
    canteen.addMenuItem(28, "Cock Chicken Tikka", 250, 33);

    canteen.addMenuItem(29, "Beef Grill Burger", 250, 42);
    canteen.addMenuItem(30, "Chicken Burger", 220, 67);
    canteen.addMenuItem(31, "Beef Grill Burger plus", 270, 25);
    canteen.addMenuItem(32, "Chicken Burger plus", 240, 54);
    canteen.addMenuItem(33, "Chicken Grill Burger plus", 260, 38);
    canteen.addMenuItem(34, "Crispy Chicken Burger", 250, 61);
    canteen.addMenuItem(35, "King Size Beef Grill Burger", 400, 17);
    canteen.addMenuItem(36, "King Size Chicken Burger", 320, 23);
    canteen.addMenuItem(37, "Hot & Spicy Beef Burger", 330, 35);
    canteen.addMenuItem(38, "Chicken Angry Burger", 290, 49);

    canteen.addMenuItem(39, "Fish Fillet", 400, 30);
    canteen.addMenuItem(40, "Fish Finger", 400, 46);
    canteen.addMenuItem(41, "Fish Cutlet", 300, 21);
    canteen.addMenuItem(42, "Captain's Fish & Chips", 350, 57);
    canteen.addMenuItem(43, "Fried Pomfret", 400, 16);

    canteen.addMenuItem(44, "Club Sandwich", 240, 40);
    canteen.addMenuItem(45, "Chicken Sandwich", 110, 73);
    canteen.addMenuItem(46, "Tuna Sandwich(D)", 260, 27);
    canteen.addMenuItem(47, "Vegetable Sandwich", 100, 59);

    canteen.addMenuItem(48, "American Style Salad Full", 240, 18);
    canteen.addMenuItem(49, "American Style Salad Half", 130, 35);
    canteen.addMenuItem(50, "Tuna Salad", 250, 43);
    canteen.addMenuItem(51, "Chicken Cashew nut Salad", 300, 26);
    canteen.addMenuItem(52, "Mixed Salad", 60, 68);
    canteen.addMenuItem(53, "Coleslaw Salad", 65, 51);

    canteen.addMenuItem(54, "Chicken Jhal Curry", 250, 32);
    canteen.addMenuItem(55, "Beef Brain Masala", 250, 14);
    canteen.addMenuItem(56, "Shrimp Curry (M) 2 Pcs.", 200, 29);

    canteen.addMenuItem(57, "Butter Naan", 70, 64);
    canteen.addMenuItem(58, "Garlic Naan", 70, 48);
    canteen.addMenuItem(59, "Plain Naan", 60, 75);
    canteen.addMenuItem(60, "Garlic Bread", 70, 37);
    canteen.addMenuItem(61, "French Fry (Large)", 100, 56);
    canteen.addMenuItem(62, "French Fry (Small)", 75, 69);
    canteen.addMenuItem(63, "Egg Vegetable Fried Rice", 100, 24);
    canteen.addMenuItem(64, "Bun", 10, 82);
    canteen.addMenuItem(65, "Cheese", 30, 45);

    canteen.addMenuItem(66, "Fresh Mango Juice", 130, 33);
    canteen.addMenuItem(67, "Fresh Orange Juice", 170, 27);
    canteen.addMenuItem(68, "Fresh Pineapple Juice", 140, 41);
    canteen.addMenuItem(69, "Fresh Apple Juice", 160, 36);
    canteen.addMenuItem(70, "Fresh Papaya Juice", 120, 52);
    canteen.addMenuItem(71, "Fresh Watermelon Juice", 130, 44);
    canteen.addMenuItem(72, "Melody Mango", 160, 31);
    canteen.addMenuItem(73, "Vergine Strawberry", 160, 22);

    canteen.addMenuItem(74, "Lemoned", 110, 63);
    canteen.addMenuItem(75, "Drinks (Medium)", 50, 58);
    canteen.addMenuItem(76, "Can Cola(Foreign)", 220, 34);
    canteen.addMenuItem(77, "Mineral Water(500ml)", 15, 91);
    canteen.addMenuItem(78, "Milk Shake", 165, 47);
    canteen.addMenuItem(79, "Lassi (Sweet)", 120, 39);
    canteen.addMenuItem(80, "Fruity Lassi", 155, 28);

    canteen.addMenuItem(81, "Vanilla Coupes", 200, 19);
    canteen.addMenuItem(82, "Fruites Coupes", 250, 25);

    canteen.addMenuItem(83, "Fresh Guava Juice", 130, 46);
    canteen.addMenuItem(84, "Fresh Lemon Juice", 100, 58);
    canteen.addMenuItem(85, "Fresh Lychee Juice", 150, 37);
    canteen.addMenuItem(86, "Fresh Pomegranate Juice", 180, 29);
    canteen.addMenuItem(87, "Fresh Grape Juice", 150, 42);
    canteen.addMenuItem(88, "Fresh Coconut Juice", 120, 35);
    canteen.addMenuItem(89, "Fresh Papaya Milkshake", 150, 24);
    canteen.addMenuItem(90, "Fresh Banana Milkshake", 140, 31);
    canteen.addMenuItem(91, "Fresh Watermelon Juice", 130, 55);
    canteen.addMenuItem(92, "Fresh Carrot Juice", 120, 28);
    canteen.addMenuItem(93, "Fresh Mixed Fruit Juice", 180, 44);
    canteen.addMenuItem(94, "Fresh Apple-Mango Juice", 170, 33);
    canteen.addMenuItem(95, "Fresh Pineapple-Mango Juice", 160, 26);
    canteen.addMenuItem(96, "Fresh Orange-Mango Juice", 170, 39);
    canteen.addMenuItem(97, "Fresh Strawberry Juice", 180, 21);
    
    
    

    int choose;

    
    while (true)
    {
        cout << "======== What are you looking for??? ========  " << endl
             << "1.Display Menu" << endl
             << "2.Place  order" << endl
             << "3.Exit" << endl;

        
        cout << "Enter Your Choice :";
        cin >> choose;

        // 
        if (choose == 3)
        {
            break;
        }

        if(choose>3 || choose<1)
        {
            cout<<"Wrong input!";
            break;
        }//input validation
        
        switch (choose)
        {
        case 1:
            
            canteen.DisplayMenu();
            break;

        case 2:
        
            
            canteen.takeOrder();
            break;

        default:
            
            cout << "Invalid Choice!!!" << endl;
        }
    }

    return 0;
}