<?php

namespace App\Http\Controllers\Api;

use App\Http\Controllers\Controller;
use App\Http\Requests\StorePostRequest;
use App\Http\Resources\PostResource;
use Illuminate\Http\Request;
use App\Models\Post;
use Illuminate\Support\Facades\Auth;

class PostController extends Controller
{
    public function index(){
        $posts = Post::with('user')->paginate(5);
        //deal with collection so return collection
        return PostResource::collection($posts);
    }
    public function show($id){
        $post=Post::with('user')->findOrFail($id);
        //deal with object
        return new PostResource($post);
    }
    public function store(StorePostRequest $request){
        $validated = $request->validated();
        if ($request->hasFile('image')) {
            $validated['image'] = $request->file('image')->store('posts', 'public');
        }

        // Create post
        
        $post = Post::create($validated);
        
        return new PostResource($post);
    }
}
