<template>
  <div id="mainapp">
    <nav class="d-flex p-4 justify-content-between py-2 bg-dark text-white">
      <a href="#" style="text-decoration: none">
        <h3 class="text-white" @click.prevent="isVisible = false">Products</h3>
      </a>
      <div class="d-flex gap-4 align-items-baseline">
        <p class="px-2 mx-2">
          {{ carts.items.length
          }}<span v-if="carts.items.length <= 1"> item</span>
          <span v-else> items</span> with total
          {{ formatCurrency(totalPrice()) }}
        </p>
        <button class="btn btn-primary" @click="isVisible = true">
          Show Carts
        </button>
      </div>
    </nav>

    <div class="row justify-content-center" v-if="isVisible == false">
      <div
        v-for="product in products"
        :key="product.id"
        class="card"
        style="width: 23rem; margin: 10px"
      >
        <img :src="product.image" :title="product.name" class="mt-2" />
        <h4 class="w-100 text-center my-4">
          {{ product.name }}
        </h4>
        <p class="text-align:justify">{{ product.description }}</p>
        <div class="car-footer">
          <div class="d-flex justify-content-between align-items-baseline">
            <p class="mx-1">
              <span
                :class="[
                  product.instock >= 5 ? 'more' : '',
                  product.instock == 0 ? 'zero' : '',
                  product.instock <= 5 && product.instock != 0 ? 'less' : '',
                ]"
                >InStock : {{ product.instock }}</span
              >
            </p>
            <button
              @click="addToCart(product)"
              :disabled="product.instock == 0"
              class="btn btn-primary"
            >
              Add To Cart
            </button>
          </div>
        </div>
      </div>
    </div>

    <div v-else>
      <h4
        v-if="carts.items.length == 0"
        class="w-100 text-center text-danger mt-2"
      >
        No items Found , Please Add items to Cart
      </h4>
      <table v-else class="table table-striped table-border text-center">
        <thead>
          <tr>
            <th>Name</th>
            <th>Price</th>
            <th>Quantity</th>
            <th>Total Price</th>
            <th>Actions</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="item in carts.items" :key="item.product.id">
            <td>{{ item.product.name }}</td>
            <td>{{ formatCurrency(item.product.price) }}</td>
            <td>{{ item.quantity }}</td>
            <td>{{ formatCurrency(item.product.price * item.quantity) }}</td>
            <td>
              <button
                class="btn btn-success"
                :disabled="item.product.instock == 0"
                @click="increaseQuantity(item)"
              >
                +
              </button>
              <span class="m-2">|</span>
              <button class="btn btn-danger" @click="decreaseQuantity(item)">
                -
              </button>
            </td>
          </tr>
        </tbody>
        <tfoot>
          <tr>
            <th colspan="3">Total Price</th>
            <th colspan="3">{{ formatCurrency(totalPrice()) }}</th>
          </tr>
          <tr>
            <th colspan="3">Total Taxes</th>
            <th colspan="3">{{ formatCurrency(totalPrice() * 0.1) }}</th>
          </tr>
          <tr>
            <th colspan="3">GrainTotal</th>
            <th>{{ formatCurrency(totalPrice() + totalPrice() * 0.1) }}</th>
          </tr>
        </tfoot>
      </table>
    </div>
  </div>
</template>

<script>
import products from "@/products.js";
export default {
  data() {
    return {
      products: JSON.parse(localStorage.getItem("product")) || products,
      isVisible: false,
      carts: {
        items: JSON.parse(localStorage.getItem("cart")) || [],
      },
    };
  },

  methods: {
    saveProducts() {
      localStorage.setItem("product", JSON.stringify(this.products));
    },
    saveCart() {
      localStorage.setItem("cart", JSON.stringify(this.carts.items));
    },
    isProductExit(product) {
      return this.carts.items.some((item) => item.product.id == product.id);
    },
    addToCart(product) {
      if (!this.isProductExit(product)) {
        this.carts.items.push({
          product: product,
          quantity: 1,
        });
      } else {
        this.carts.items.find((item) => item.product.id == product.id)
          .quantity++;
      }
      product.instock--;
      this.saveCart();
      this.saveProducts();
    },
    totalPrice() {
      let result = 0;
      for (let i = 0; i < this.carts.items.length; i++) {
        result +=
          this.carts.items[i].quantity * this.carts.items[i].product.price;
      }
      return result;
    },
    increaseQuantity(item) {
      item.quantity++;
      item.product.instock--;
      this.saveCart();
      this.saveProducts();
    },
    decreaseQuantity(item) {
      item.quantity--;
      if (item.quantity == 0) {
        //remove item
        this.carts.items.splice(
          this.carts.items.findIndex((i) => i.product.id == item.product.id),
          1
        );
      }
      item.product.instock++;
      this.saveCart();
      this.saveProducts();
    },
    formatCurrency(value) {
      return Intl.NumberFormat("en-US", {
        style: "currency",
        currency: "USD",
        minimumFractionDigits: 0,
      }).format(value);
    },
  },
};
</script>

<style scoped>
.zero {
  color: red;
}

.less {
  color: orange;
}

.more {
  color: green;
}

.zero,
.less,
.more {
  font-weight: bold;
}
</style>
