#include <stdio.h>

#define ARTICHOKE 2.05
#define BEET 1.15
#define CARROT 1.09
#define DISCOUNT 0.05 // before delivery if purchase >= $100
#define DELIVERY_5 6.50 // <=5lb
#define DELIVERY_5_20 14.0
#define DELIVERY_A 0.5 // +$0.5 for every lb if goods > 20lb

int main() {
  int ch;
  float w_beets=0, w_arts=0, w_carrots=0;

  do {
    for (int i=0; i<50; i++) {putchar('-');}
    putchar('\n');
    printf("\tWhat do you want to order?\n");
    printf("a) artichoke\t\tb) beet\nc) caroots\t\tq) make the order\n");
    for (int i=0; i<50; i++) {putchar('-');}
    putchar('\n');

    ch=getchar();

    while ((getchar()) != '\n');

    float input;
    switch (ch) {
      case 'a':
        printf("Enter artichokes weight (lb): ");
        scanf("%f", &input);
        w_arts += input;
        break;
      case 'b':
        printf("Enter beets weight (lb): ");
        scanf("%f", &input);
        w_beets += input;
        break;
      case 'c':
        printf("Enter carrots weight (lb): ");
        scanf("%f", &input);
        w_carrots += input;
        break;
      case 'q':
        printf("Oh, that's all? Let's calculate...\n");
        break; 
      default:
        printf("\nOops! Wrong command! Try again.\n");
    }
    putchar('\n');

  } while (ch != 'q');

    printf("Now ur order: %.2flb artichokes, %.2flb beets, %.2flb carrots\n\n",
           w_arts, w_beets, w_carrots);
  
  float weight = w_arts + w_beets + w_carrots;
  float cost_arts = w_arts*ARTICHOKE;
  float cost_beets = w_beets*BEET;
  float cost_carrots = w_carrots*CARROT;
  float cost = cost_arts + cost_beets + cost_carrots;
  float discount=0;
  if (cost >= 100) discount = cost*DISCOUNT;
  float delivery=0;
  if (weight <= 5) {delivery = weight*DELIVERY_5;}
  else if (weight > 5 && weight <= 20) {delivery = weight*DELIVERY_5_20;}
  else {delivery = DELIVERY_5_20 + (weight-20)*DELIVERY_A;}
  float total_cost = cost - discount + delivery;
  
  printf("\n");
  printf("\tCheck.\n");
  for (int i=0; i<23; i++) {putchar('*');}
  putchar('\n');

  printf("lb cost: ");
  if (weight <= 5) {printf("$%.2f\n", DELIVERY_5);}
  else if (weight > 5 && weight <= 20) {printf("$%.2f\n", DELIVERY_5_20);}
  else {printf("$%.2f + $%.2f/lb\n", DELIVERY_5_20, DELIVERY_A);}
  printf("weight: %.2flb\n", weight);

  printf("artichoke: $%.2f/lb\nbeet: $%.2f/lb\ncarrot: $%.2f/lb\n",
         ARTICHOKE, BEET, CARROT);

  printf("cost: $%.2f\n", cost);
  if (discount) {printf("discount: $%.2f\n", discount);}
  printf("delivery: $%.2f\n", delivery);
  
  printf("\ntotal order cost: $%.2f\n", total_cost);

  for (int i=0; i<23; i++) {putchar('*');}
  putchar('\n');
  
  return 0;
}
