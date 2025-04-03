<?php

namespace App\Http\Controllers;

use App\Http\Requests\StorePostRequest;
use App\Http\Requests\UpdatePostRequest;
use Illuminate\Http\Request;
use App\Models\Post;
use App\Models\User;
use Illuminate\Support\Facades\Storage;

class PostController extends Controller
{
    public function index()
    {
        $posts = Post::paginate(5);
        
        return view('posts.index', ['posts' => $posts]);
    }
    public function create()

    {
        $users = User::all();
        return view('posts.create', ['users' => $users]);
    }
    public function show($slug)
    {
        $post = Post::where('slug', $slug)->firstOrFail();
        return view('posts.show', ['post' => $post]);
    }

    public function store(StorePostRequest $request)
    {
        
        $validated = $request->validated();
        // dd($request->validated(),$request->image);

        if ($request->hasFile('image')) {
            $validated['image'] = $request->file('image')->store('posts', 'public');
        }
        // Create post
        $post = Post::create($validated);

        return to_route('posts.show', $post->slug);
    }
    public function edit($id)
    {
        $post = Post::find($id);
        $users = User::all();
        return view('posts.edit', ['post' => $post,'users'=>$users]);
    }

    public function update(UpdatePostRequest $request, $id)
{
    // Find the post
    $post = Post::find($id);

    if (!$post) {
        return redirect()->route('posts.index')->with('error', 'Post not found');
    }

    $validated = $request->validated();

    if ($request->hasFile('image')) {
        // Delete old image if it exists
        if ($post->image) {
            Storage::disk('public')->delete($post->image);
        }

        // Store new image
        $validated['image'] = $request->file('image')->store('posts', 'public');
    }

    // Update post
    $post->update($validated);

    return redirect()->route('posts.index')->with('success', 'Post updated successfully');
}

public function destroy($id)
{
    $post = Post::find($id);

    if (!$post) {
        return redirect()->route('posts.index')->with('error', 'Post not found');
    }

    // Delete the image if it exists
    if ($post->image) {
        Storage::disk('public')->delete($post->image);
    }

    // Delete the post
    $post->delete();

    return redirect()->route('posts.index')->with('success', 'Post deleted successfully.');
}

    
}
