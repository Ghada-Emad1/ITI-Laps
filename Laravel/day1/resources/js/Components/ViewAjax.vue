<template>
  <div>
    <!-- Button to Open Modal -->
    <button @click="fetchPost" class="bg-blue-500 text-white px-4 py-2 rounded">
      View Post
    </button>

    <!-- Modal -->
    <div v-if="showModal" class="fixed inset-0 bg-gray-900 bg-opacity-50 flex items-center justify-center">
      <div class="bg-white p-5 rounded shadow-lg w-1/3">
        <h2 class="text-xl font-bold mb-2">{{ post.title }}</h2>
        <p class="text-gray-700 mb-2">{{ post.description }}</p>
        <p class="text-sm text-gray-600">Posted by: {{ post.username }} ({{ post.useremail }})</p>
        
        <!-- Close Button -->
        <button @click="showModal = false" class="mt-3 bg-red-500 text-white px-4 py-2 rounded">
          Close
        </button>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  props: {
    id: {
      type: Number,
      required: true
    }
  },
  data() {
    return {
      post: {},
      showModal: false
    };
  },
  methods: {
    async fetchPost() {
      try {
        const response = await axios.get(`/api/posts/${this.id}`);
        this.post = response.data;
        this.showModal = true;
      } catch (error) {
        console.error("Error fetching post:", error);
      }
    }
  }
};
</script>
