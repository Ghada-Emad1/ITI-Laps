<x-layout :title="'Edit Post'">
    <div class="max-w-3xl mx-auto">
        <div class="bg-white rounded-lg shadow overflow-hidden">
            <div class="px-6 py-4 border-b border-gray-200">
                <h2 class="text-xl font-semibold text-gray-800">Edit Post</h2>
            </div>

            <div class="px-6 py-4">
                @if ($errors->any())
                    <div role="alert" class="max-w-3xl mx-auto mb-4 rounded-sm border-s-4 border-red-500 bg-red-50 p-4">
                        <strong class="block font-medium text-red-800"> Something went wrong </strong>
                        <ul>
                            @foreach ($errors->all() as $error)
                                <li>{{ $error }}</li>
                            @endforeach

                        </ul>
                    </div>
                @endif
                <form method="POST" action="{{ route('posts.update', $post['id']) }}" enctype="multipart/form-data">
                    @csrf
                    @method('PUT')

                    <!-- Title Input -->
                    <div class="mb-4">
                        <label for="title" class="block text-sm font-medium text-gray-700 mb-1">Title</label>
                        <input name="title" type="text" id="title" value="{{ $post['title'] }}"
                            class="w-full rounded-md border-gray-300 shadow-sm focus:border-blue-500 focus:ring focus:ring-blue-200 focus:ring-opacity-50 py-2 px-3 border">
                    </div>

                    <!-- Description Textarea -->
                    <div class="mb-4">
                        <label for="description"
                            class="block text-sm font-medium text-gray-700 mb-1">Description</label>
                        <textarea name="description" id="description" rows="5"
                            class="w-full rounded-md border-gray-300 shadow-sm focus:border-blue-500 focus:ring focus:ring-blue-200 focus:ring-opacity-50 py-2 px-3 border">{{ $post['description'] }}</textarea>
                    </div>

                    <!-- Post Creator Select -->
                    <div class="mb-6">
                        <label for="creator" class="block text-sm font-medium text-gray-700 mb-1">Post Creator</label>
                        <select name="user_id" id="creator"
                            class="w-full rounded-md border-gray-300 shadow-sm focus:border-blue-500 focus:ring focus:ring-blue-200 focus:ring-opacity-50 py-2 px-3 border bg-white">
                            @foreach ($users as $user)
                                <option value="{{ $user->id }}">{{$user->name}}</option>
                            @endforeach
                        </select>
                    </div>

                    <div class="mb-6">
                        <label for="image">Current Image:</label>
                        @if ($post->image)
                            <img src="{{ $post->image }}" width="150">
                            
                        @else
                            <p>No Image</p>
                        @endif
                        <form action="{{ route('posts.deleteImage', $post->id) }}" method="POST" style="display:inline;">
                            @csrf
                            @method('DELETE')
                            <button type="submit" class="bg-red-500 text-white px-4 py-2 rounded">Delete Image</button>
                        </form>
                        
                        <label for="image">Change Image:</label>
                        <input type="file" name="image">
                    </div>

                    <!-- Submit Button -->
                    <div class="flex justify-end">
                        <button type="submit"
                            class="px-4 py-2 bg-blue-600 text-white font-medium rounded-md hover:bg-blue-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-blue-500 hover:cursor-pointer">
                            Update
                        </button>
                    </div>
                </form>
            </div>
        </div>
    </div>
</x-layout>