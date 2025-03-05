<template>
  <Navbar @changeView="isVisible = $event" />
  <WishList v-if="isVisible" :wishList="wishList" @removeBook="removeFromWishlist" />
  <Books v-else :books="books" @addtowishlist="addBook" />
</template>

<script>
import books from "@/books.js";
import Navbar from "./components/Navbar.vue";
import Books from "./components/Books.vue";
import WishList from "./components/WishList.vue";

export default {
  data() {
    return {
      books: books,
      wishList: [],
      isVisible: false,
    };
  },
  components: {
    Navbar,
    Books,
    WishList,
  },
  methods: {
    removeFromWishlist(id) {
      this.wishList = this.wishList.filter((item) => item.ISBN !== id);
    },
    addBook(book) {
      if (!this.wishList.some((b) => b.ISBN === book.ISBN)) {
        this.wishList.push(book);
      }
    },
  },
};
</script>

<style>
</style>
