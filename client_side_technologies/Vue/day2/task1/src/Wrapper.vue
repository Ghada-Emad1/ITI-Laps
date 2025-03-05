<template>
  <div>
    <Cart :products="products">
        
    </Cart>
  </div>
</template>

<script >
import Cart from './components/Cart.vue';
import products from "@/products.js";
export default {
    components: {
        Cart
    }
}

</script>

<style>

</style>