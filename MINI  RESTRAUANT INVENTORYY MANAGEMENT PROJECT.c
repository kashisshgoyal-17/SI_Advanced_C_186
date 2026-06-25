#include<stdio.h>
int main()
{
	char names[5][30]= {"NOODLES","MOMOS","PANNER TIKKA","BURGER","SOFT DRINKS"};
	float price[5]= {120.0,100.0,250.0,60.0,100.0};
	int choice;
	printf("\t\t======INVENTORY MANAGEMENT SYSTEM PROJECT======\n");
	printf("1.VIEW MENU\n");
	printf("2.PLACE AN ORDER\n");
	printf("3.EXIT\n");
	printf("ENTER THE CHOICE\n");
	scanf("%d",&choice);
	switch(choice) {
	case 1:
		printf("\n---- MENU ----\n");
		for (int i = 0; i < 5; i++) {
			printf("%d. %s - Rs.%.2f\n", i+1, names[i], price[i]);
		}
		break;

	case 2: {

		int n, item, qty;
		float total = 0;
		printf("\n---- MENU ----\n");
		for (int i = 0; i < 5; i++) {
			printf("%d. %s - Rs.%.2f\n", i+1, names[i], price[i]);
		}
		printf("No.of items to be selected? ");
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			printf("Item number(1-5): ");
			scanf("%d", &item);
			printf("Quantity: ");
			scanf("%d", &qty);
			int index = item - 1;
			float subtotal = price[index] * qty;
			total = total + subtotal;
			printf("%s x %d = Rs.%.2f\n", names[index], qty, subtotal);
		}
		float gst = total * 0.05;
		float grandTotal = total + gst;
		printf("\n---- BILL ----\n");
		printf("Subtotal: Rs.%.2f\n", total);
		printf("GST (5%%): Rs.%.2f\n", gst);
		printf("Grand Total: Rs.%.2f\n", grandTotal);
		break;
	}
	case 3:
		printf("THANK YOU FOR VISIT\n");
		break;
	default:
		printf("INVALID\n");
	}
	return 0;
}

