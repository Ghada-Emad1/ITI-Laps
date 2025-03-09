<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Post;
use App\Models\User;

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
    public function show($id)
    {
        $post = Post::find($id);

        return view('posts.show', ['post' => $post]);
    }
    public function store()
    {
        $title = request()->title;
        $description = request()->description;
        $postCreator=request()->postCreator;

        $post = Post::create([
            'title' => $title,
            'description' => $description,
            'user_id' => $postCreator
        ]);
        return to_route('posts.show', $post->id);
    }
    public function edit($id)
    {
        $post = Post::find($id);
        $users = User::all();
        return view('posts.edit', ['post' => $post,'users'=>$users]);
    }

    public function update($id)
    {
        $post= Post::find($id);
        // dd($post->title);
        $post->title = request()->title;
        $post->description = request()->description;
        $post->user_id = request()->user_id;
        $post->save();
        return redirect()->route('posts.index');
    }


    public function destroy($id)
    {

        $deleted = Post::where('id', $id)->delete();
        dd($deleted);
        if($deleted){
            return redirect()->route('posts.index');
        }
        
        
    }
}
