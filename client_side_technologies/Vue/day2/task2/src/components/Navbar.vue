<template>
  <div>
    <nav class="fixed-top bg-dark d-flex p-4 justify-content-between">
        <a href="#"style="text-decoration: none"><h4 class="text-white" @click.prevent="$emit('changeView',false)">Books</h4></a>
        <button class="btn btn-primary" @click="$emit('changeView',true)">Show Carts</button>
    </nav>
    
  </div>
</template>

<script >
export default {
  emits:['changeView'],
}

</script>

<style>

</style>