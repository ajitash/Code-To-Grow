Name: M.Naga Ajitesh
Reg N.o: AP25110090150


**Approach:**  
This C program provides a basic inventory management solution for up to 10 products.
At startup, it asks the user to input how many products are being managed (up to 10), and then gather the ID, name, price, and quantity for each product.
The program calculates each product's total stock value (quantity × price), and tracks which products have the highest and lowest values.
After setup, a menu-driven loop allows the user to display all product information, see the total inventory value, find products with the highest and lowest stock,
or search for a product by its ID. The system is interactive and keeps running until the user opts to exit.

**Variables:**  
ID[10]: Stores product IDs.
quantity[10]: Stores quantities in stock for products.
price[10]: Stores price per item for products.
value[10]: Stores calculated value (quantity × price) for products.
name[10][55]: Stores product names.
products: Number of products in the inventory.
choice: User's menu choice.
searchID: Product ID to search for.
totalvalue: Holds the sum of all inventory values.
highest: Index of the product with the highest stock value.
lowest: Index of the product with the lowest stock value.
i: Loop iterator.
found: Used when searching products by ID to track if a match was found.
