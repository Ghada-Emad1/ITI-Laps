<template>
  <div style="margin-top: 100px">
    <table
      v-if="wishList.length > 0"
      class="table table-striped table-border text-center"
    >
      <thead>
        <tr>
          <th>Category</th>
          <th>Author</th>
          <th>Price</th>
          <th>Remove</th>
          
        </tr>
      </thead>
      <tbody>
        <tr v-for="book in wishList" :key="book.ISBN">
          <td>{{ book.category }}</td>
          <td>{{ book.author }}</td>
          <td>{{ formatCurrency(book.price) }}</td>
          <td>
            <button
              class="btn btn-danger"
              @click="$emit('removeBook', book.ISBN)"
            >
              Delete
            </button>
          </td>
        </tr>
      </tbody>
    </table>
    <div v-else-if="wishList.length === 0">
      <h1 class="text-danger font-bold text-center">
        Cart is Empty Please Select A book
      </h1>
    </div>
    <div
      v-if="wishList.length > 0"
      class="d-flex justify-content-center align-items-center  p-3 w-100"
    >
      <h2 class="m-0">Total Price is {{ formatCurrency(totalPrice()) }}</h2>
    </div>
  </div>
</template>

<script>
export default {
  props: {
    wishList: [],
  },
  methods: {
    formatCurrency(value) {
      return Intl.NumberFormat("en-US", {
        style: "currency",
        currency: "USD",
        minimumFractionDigits: 0,
      }).format(value);
    },
    totalPrice() {
      let sum = 0;
      for (let i = 0; i < this.wishList.length; i++) {
        sum += this.wishList[i].price;
      }
      return sum;
    },
  },
};
</script>

<style scoped></style>
