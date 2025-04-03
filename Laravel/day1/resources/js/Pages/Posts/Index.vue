<template>
    <div>
        <!-- Create Post Button -->
        <div class="text-center">
            <Link :href="route('posts.create')"
                class="mt-4 px-4 py-2 bg-green-600 text-white font-medium rounded-md hover:bg-green-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-green-500">
                Create Post
            </Link>
        </div>

        <!-- Table Component -->
        <div class="mt-6 rounded-lg border border-gray-200">
            <div class="overflow-x-auto rounded-t-lg">
                <table class="min-w-full divide-y-2 divide-gray-200 bg-white text-sm">
                    <thead class="text-left">
                        <tr>
                            <th class="px-4 py-2 font-medium whitespace-nowrap text-gray-900">#</th>
                            <th class="px-4 py-2 font-medium whitespace-nowrap text-gray-900">Title</th>
                            <th class="px-4 py-2 font-medium whitespace-nowrap text-gray-900">Slug</th>
                            <th class="px-4 py-2 font-medium whitespace-nowrap text-gray-900">Posted By</th>
                        </tr>
                    </thead>
                    <tbody class="divide-y divide-gray-200">
                        <tr v-for="(post, index) in posts" :key="post.id">
                            <td class="px-4 py-2">{{ index + 1 }}</td>
                            <td class="px-4 py-2">{{ post.title }}</td>
                            <td class="px-4 py-2">{{ post.slug }}</td>
                            <td class="px-4 py-2">{{ post.user.name }}</td>
                        </tr>
                    </tbody>
                </table>
            </div>
        </div>
    </div>
</template>

<script>
import { Link } from '@inertiajs/vue3';

export default {
    props: {
        posts: Array
    }
};
</script>
