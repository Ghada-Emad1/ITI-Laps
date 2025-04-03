<x-layout>
    <div class="text-center">
        <a href="{{ route('posts.create') }}"
            class="mt-4 px-4 py-2 bg-green-600 text-white font-medium rounded-md hover:bg-green-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-green-500">
            Create Post
        </a>
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
                        <th class="px-4 py-2 font-medium whitespace-nowrap text-gray-900">Created At</th>
                         <th class="px-4 py-2 font-medium whitespace-nowrap text-gray-900">Image</th>
                        <th class="px-4 py-2 font-medium whitespace-nowrap text-gray-900">Actions</th>
                    </tr>
                </thead>
                <tbody class="divide-y divide-gray-200">
                    @foreach ($posts as $post)
                  
                        <tr>
                            
                            <td class="px-4 py-2 font-medium whitespace-nowrap text-gray-900">{{ $post->id }}</td>
                            <td class="px-4 py-2 whitespace-nowrap text-gray-700">{{ $post->title }}</td>
                            <td><a href="{{ route('posts.show', $post->slug) }}">{{ $post->slug }}</a></td>
                            <td class="px-4 py-2 whitespace-nowrap text-gray-700">{{ $post->user ? $post->user->name : 'No User Found' }}</td>
                            <td class="px-4 py-2 whitespace-nowrap text-gray-700">{{ $post->formatted_created_at }}</td>
                        <td>
                            @if ($post->image)
                                <img src="{{ $post->image }}" alt="">
                            @else
                                No Image
                            @endif
                        </td>

                            <td class="px-4 py-2 whitespace-nowrap text-gray-700 space-x-2">
                                <a href="{{ route('posts.show', $post->slug) }}">
                                    <x-button type="primary">View</x-button>
                                </a>

                                <a href="{{ route('posts.edit', $post['id']) }}">
                                    <x-button type="secondary">Edit</x-button>
                                </a>

                                <form action="{{ route('posts.destroy', $post->id) }}" method="POST" class="inline"
                                    onsubmit="return confirm('Are you sure you want to delete this post?');">
                                    @csrf
                                    @method('DELETE')
                                    <button type="submit" class="bg-red-600 text-white px-4 py-2 rounded-md hover:bg-red-700">
                                        Delete
                                    </button>
                                </form>

                            </td>

                        </tr>
                    @endforeach
                </tbody>
            </table>
        </div>

        <!-- Pagination -->
        <div class="mt-4">
            {{ $posts->links() }}
        </div>
    </div>
</x-layout>