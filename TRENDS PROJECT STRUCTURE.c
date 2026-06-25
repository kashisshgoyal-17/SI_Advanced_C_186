// Roll Number:- 2502900100186
// Inventory Management system :- TRENDS
// Using Structure

#include <stdio.h>
#include <string.h>

struct Product {
    int  id;
    char name[50];
    char brand[50];
    int  quantity;
    int  mrp;
};

int main()
{
    struct Product p[] = {
        {1001, "T_Shirts",  "Peter_England", 89,  500 },
        {1002, "Shirts",    "Nike",          90,  600 },
        {1003, "Jeans",     "US_Polo",       108, 699 },
        {1004, "Pants",     "Zara",          123, 799 },
        {1005, "Socks",     "Armani",        34,  899 },
        {1006, "Trousers",  "Arrow",         56,  999 },
        {1007, "Bags",      "H&M",           89,  2999},
        {1008, "Shoes",     "Colors",        78,  1999},
        {1009, "Perfumes",  "Gucci",         156, 1200},
        {1010, "Caps",      "LV",            45,  699 }
    };
    int n = sizeof(p) / sizeof(p[0]);

    char *sizes[] = {"S", "M", "L", "XL", "XXL", "XXXL"};

    int   bill_index[100];
    int   bill_qty[100];
    float bill_total[100];
    int   bill_count = 0;
    float grand_total = 0;
    int   choice;

    do {
        printf("\n\t\t\tTRENDS INVOICE\n");
        printf("\t\t\t1. Stock Availability\n");
        printf("\t\t\t2. Purchase Item\n");
        printf("\t\t\t3. Checkout & Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        while (choice < 1 || choice > 3) {
            printf("Invalid Choice! Enter again: ");
            scanf("%d", &choice);
        }

        if (choice == 1) {
            printf("\n%-6s  %-14s  %-14s  %-6s  %s\n",
                   "ID", "Product", "Brand", "Stock", "MRP");
            printf("=====================================================\n");
            for (int i = 0; i < n; i++) {
                printf("%-6d  %-14s  %-14s  %-6d  %d\n",
                       p[i].id, p[i].name, p[i].brand,
                       p[i].quantity, p[i].mrp);
            }
        }   // ✅ FIX: Added missing closing brace for choice == 1

        else if (choice == 2) {
            int pid, found = 0, qty, sc;

            printf("Enter Product ID: ");
            scanf("%d", &pid);

            for (int i = 0; i < n; i++) {
                if (p[i].id == pid) {
                    found = 1;

                    if (p[i].quantity == 0) {
                        printf("'%s' is out of stock!\n", p[i].name);
                        break;
                    }

                    printf("Product : %s (%s)\n", p[i].name, p[i].brand);
                    printf("MRP     : Rs. %d\n",  p[i].mrp);
                    printf("Stock   : %d\n",      p[i].quantity);

                    printf("Select Size: 1.S  2.M  3.L  4.XL  5.XXL  6.XXXL\n");
                    printf("Enter (1-6): ");
                    scanf("%d", &sc);
                    while (sc < 1 || sc > 6) {
                        printf("Invalid! Enter (1-6): ");
                        scanf("%d", &sc);
                    }

                    printf("Enter Quantity: ");
                    scanf("%d", &qty);
                    while (qty <= 0 || qty > p[i].quantity) {
                        printf("Invalid! Max %d, Enter again: ", p[i].quantity);
                        scanf("%d", &qty);
                    }

                    float total = p[i].mrp * qty;

                    printf("\n--- Item Added ---\n");
                    printf("%s | Size: %s | Qty: %d | Total: Rs.%.2f\n",
                           p[i].name, sizes[sc-1], qty, total);

                    p[i].quantity     -= qty;
                    bill_index[bill_count] = i;
                    bill_qty[bill_count]   = qty;
                    bill_total[bill_count] = total;
                    bill_count++;
                    grand_total += total;
                    break;
                }
            }
            if (!found) printf("Product ID %d not found!\n", pid);
        }

        else if (choice == 3) {
            printf("\n====== CHECKOUT RECEIPT ======\n");
            if (bill_count == 0) {
                printf("No items purchased.\n");
            } else {
                printf("%-14s  %-14s  %-4s  %s\n",
                       "Product", "Brand", "Qty", "Total");
                printf("------------------------------------------\n");
                for (int b = 0; b < bill_count; b++) {
                    int i = bill_index[b];
                    printf("%-14s  %-14s  %-4d  Rs.%.2f\n",
                           p[i].name, p[i].brand,
                           bill_qty[b], bill_total[b]);
                }
                printf("------------------------------------------\n");
                printf("GRAND TOTAL: Rs. %.2f\n", grand_total);
            }
            printf("Thank you for shopping at TRENDS!\n");
        }

    } while (choice != 3);

    return 0;
}