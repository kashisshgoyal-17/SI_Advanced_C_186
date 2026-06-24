// Roll Number:- 2502900100186
// Inventory Management system :- TRENDS
#include <stdio.h>
#include <string.h>

int main()
{
    int   Product_ID[]       = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010};
    char *Products[]         = {"T_Shirts","Shirts","Jeans","Pants","Socks","Trousers","Bags","Shoes","Perfumes","Caps"};
    char *Brands[]           = {"Peter_England","Nike","US_Polo","Zara","Armani","Arrow","H&M","Colors","Gucci","LV"};
    int   Product_Quantity[] = {89, 90, 108, 123, 34, 56, 89, 78, 156, 45};
    int   Product_MRP[]      = {500, 600, 699, 799, 899, 999, 2999, 1999, 1200, 699};
    char *Product_Size[]     = {"S", "M", "L", "XL", "XXL", "XXXL"};

    int   bill_ids[100];
    int   bill_quantity[100];
    float bill_totals[100];   
    int   bill_count = 0;
    float total_bill = 0;
    int   choice;

    do {
        printf("\n\t\t\tTRENDS INVOICE\n");
        printf("\t\t\t1. Stock Availability\n");
        printf("\t\t\t2. Purchase Item\n");
        printf("\t\t\t3. Checkout & Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        
        while (choice < 1 || choice > 3)
        {
            printf("You Have Entered Invalid Choice!!!!!!\n");
            printf("\t\t\t1. Stock Availability\n");
            printf("\t\t\t2. Purchase Item\n");
            printf("\t\t\t3. Checkout & Exit\n");
            printf("Enter Your Correct Choice: ");
            scanf("%d", &choice);
        }

        
        if (choice == 1)
        {
            printf("\n%-6s  %-14s  %-14s  %-6s  %s\n",
                   "ID", "Product", "Brand", "Stock", "MRP(Rs)");
            printf("=============================================================\n");
            for (int i = 0; i < (int)(sizeof(Product_ID) / sizeof(Product_ID[0])); i++)
            {
               
                printf("%-6d  %-14s  %-14s  %-6d  %d\n",
                       Product_ID[i], Products[i], Brands[i],
                       Product_Quantity[i], Product_MRP[i]);
            }
        }

        
        else if (choice == 2)
        {
            int PID, found = 0, quantity, size_choice;

            printf("Enter Product ID to purchase: ");
            scanf("%d", &PID);

            for (int i = 0; i < (int)(sizeof(Product_ID) / sizeof(Product_ID[0])); i++)
            {
                if (Product_ID[i] == PID)
                {
                    found = 1;

                    if (Product_Quantity[i] == 0)
                    {
                       
                        printf("Sorry, '%s' is out of stock!\n", Products[i]);
                        break;
                    }

                    printf("Product : %s (%s)\n", Products[i], Brands[i]);
                    printf("MRP     : Rs. %d\n",  Product_MRP[i]);
                    printf("Stock   : %d units\n", Product_Quantity[i]);

                
                    printf("Select the Size:\n");
                    for (int s = 0; s < 6; s++)
                        printf("  %d. %s\n", s + 1, Product_Size[s]);
                    printf("Enter size option (1-6): ");
                    scanf("%d", &size_choice);
                    while (size_choice < 1 || size_choice > 6)
                    {
                        printf("Invalid size choice! Enter again (1-6): ");
                        scanf("%d", &size_choice);
                    }

                    
                    printf("Enter Quantity: ");
                    scanf("%d", &quantity);
                    while (quantity <= 0 || quantity > Product_Quantity[i])
                    {
                        printf("Invalid Quantity! Available: %d, Enter again: ",
                               Product_Quantity[i]);
                        scanf("%d", &quantity);
                    }

                    float item_total = Product_MRP[i] * quantity;

                    printf("\n========= Item Summary =========\n");
                    printf("Product  : %s | Size : %s | Quantity : %d\n",
                           Products[i], Product_Size[size_choice - 1], quantity);
                    printf("MRP      : Rs. %d\n", Product_MRP[i]);
                    printf("Item Total: Rs. %.2f\n", item_total);

                
                    Product_Quantity[i]      -= quantity;
                    bill_ids[bill_count]      = i;
                    bill_quantity[bill_count] = quantity;
                    bill_totals[bill_count]   = item_total;   // BUG 6 FIX
                    bill_count++;
                    total_bill += item_total;

                    break;
                }
            }

            if (!found)
                printf("Product ID %d not found!\n", PID);
        }

        
        else if (choice == 3)
        {
            printf("\n\t\t\t====== CHECKOUT RECEIPT =======\n");
            if (bill_count == 0)
            {
                printf("No items purchased.\n");
            }
            else
            {
                
                printf("%-14s  %-14s  %-4s  %s\n",
                       "Product", "Brand", "Qty", "Total(Rs)");
                printf("--------------------------------------------------\n");
                for (int b = 0; b < bill_count; b++)
                {
                    int i = bill_ids[b];
                    printf("%-14s  %-14s  %-4d  %.2f\n",
                           Products[i], Brands[i],
                           bill_quantity[b], bill_totals[b]);
                }
                printf("--------------------------------------------------\n");
                printf("GRAND TOTAL: Rs. %.2f\n", total_bill);
            }
            printf("Thank you for shopping at TRENDS!\n");
        }

    } while (choice != 3);

    return 0;
}
