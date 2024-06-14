#include "Margherita.hpp"
#include "Funghi.hpp"
#include "Pizzeria.hpp"

int main()
{
    Pizzeria bravo("Bravo Pizza");
    Pizzas pizzas = {new Margherita, new Funghi};

    auto orderId = bravo.makeOrder(pizzas);
    auto price = bravo.calculatePrice(orderId);
    bravo.bakePizzas(orderId);
    bravo.completeOrder(orderId);

    return 0;
}
