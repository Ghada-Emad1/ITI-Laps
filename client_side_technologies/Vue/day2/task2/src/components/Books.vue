<template>
  <div class="container " style="margin-top: 120px;">
    <div class="d-flex flex-wrap justify-content-center gap-4">
      <div class="card" style="width: 23rem; min-height: 350px; max-height: 400px; display: flex; flex-direction: column;" v-for="book in books" :key="book.ISBN">
        <img :src="book.image" class="card-img-top" style="height: 200px; object-fit: cover;" alt="Book Image" />
        <div class="card-body d-flex flex-column flex-grow-1">
          <div class="d-flex justify-content-between">
            <h5 class="card-title">{{ book.category }}</h5>
            <p class="card-text">{{ book.author }}</p>
          </div>
          <div class="d-flex justify-content-between">
            <h5 :class="[book.pages < 50 ? 'less' : 'more', 'card-title']">No.{{ book.pages }}</h5>
            <p class="card-text">{{ book.price }}</p>
          </div>
          <div class="d-flex justify-content-between mt-auto">
            <h5 class="card-title">{{ book.ISBN }}</h5>
            <button class="btn btn-danger" @click.once="addTowishList(book)">Add</button>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  props: {
    books: Array,
  },
  methods: {
    addTowishList(book) {
      this.$emit('addtowishlist', book);
      
    }
  }
 
};
</script>

<style scoped>
.less {
  color: red;
}

.more {
  color: green;
}

.card-body {
  flex-grow: 1;
}

.card-img-top {
  object-fit: cover;
}
</style>
