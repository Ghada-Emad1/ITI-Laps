<?php

namespace App\Http\Responses;

use Illuminate\Contracts\Support\Responsable;
use App\Models\Post;

class PostResponse implements Responsable
{
    protected $post;

    public function __construct(Post $post)
    {
        $this->post = $post;
    }

    public function toResponse($request)
    {
        return response()->json([
            'title'       => $this->post->title,
            'description' => $this->post->description,
            'username'    => $this->post->user->name,
            'useremail'   => $this->post->user->email,
        ]);
    }
}
