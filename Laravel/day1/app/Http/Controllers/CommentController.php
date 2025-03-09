<?php

namespace App\Http\Controllers;

use App\Models\Comment;
use App\Models\Post;
use Illuminate\Http\Request;

class CommentController extends Controller
{
    public function store($id)
    {
        $body = request()->body;
        $user_id = request()->user_id; 

        $post = Post::findOrFail($id); 

        $post->comments()->create([
            'body' => $body,]);

        return redirect()->route('posts.show', $post->id);
    }

    public function destroy($id)
    {
        $deleted = Comment::where('id', $id)->delete();
        dd($deleted);
        if ($deleted) {
            return redirect()->route('posts.index');
        }
    }
}
