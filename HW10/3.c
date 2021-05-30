#include <stdio.h>

/// @struct for Product data
typedef struct Product
{
    char name[100];
    float price;
    int quantity;
    float amount;
} Product;

int main()
{
    /// @declare product
    Product product;

    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter price: ");
    scanf("%f", &product.price);
    printf("Enter quantity: ");
    scanf("%d", &product.quantity);
    /// calculate amount of products
    product.amount = product.price * product.quantity;

    puts("");

    printf("Name: %s\n", product.name);
    printf("Price: %f\n", product.price);
    printf("Quantity: %d\n", product.quantity);
    printf("Total Amount: %f\n", product.amount);
}