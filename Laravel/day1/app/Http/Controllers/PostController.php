<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class PostController extends Controller
{
    public function index()
    {
        $posts = [
            ["id" => 1, "title" => "PHP", 'posted_by' => 'Ghada', 'created_at' => '2025-03-08 7:57 pm '],
            ["id" => 2, "title" => "Laravel", 'posted_by' => 'Gehad', 'created_at' => '2025-03-04 5:05 pm '],

        ];
        return view('posts.index', ['posts' => $posts]);
    }
    public function create()
    {
        return view('posts.create');
    }
    public function show($id)
    {
        $post = [
            'id' => 1,
            'title' => 'PHP',
            'description' => 'programmaing language',
            'posted_by' => [
                'name' => 'Ghada',
                'email' => 'ghada@gmail.com',
                'created_at' => 'Thursday 25th of December 1975 02:15:16 PM'
            ],
            'created_at' => '2025-03-08 7:57 pm',
        ];
        return view('posts.show', ['post' => $post]);
    }
    public function store()
    {
        $title = request()->title;
        $description = request()->description;
        return to_route('posts.show', 1);
    }
    public function edit($id)
    {
        $post = [
            'id' => 1,
            'title' => 'PHP',
            'description' => 'programmaing language',
            'posted_by' => [
                'name' => 'Ghada',
                'email' => 'ghada@gmail.com',
                'created_at' => 'Thursday 25th of December 1975 02:15:16 PM'
            ],
            'created_at' => '2025-03-08 7:57 pm',
        ];
        return view('posts.edit', ['post' => $post]);
    }

    public function update($id)
    {
        // Dummy posts array
        $posts = [
            [
                'id' => 1,
                'title' => 'PHP',
                'description' => 'programmaing language',
                'posted_by' => 'Ghada',
                'created_at' => '2025-03-08 7:57 pm',
            ],
            ["id" => 2, "title" => "Laravel", 'posted_by' => 'Gehad', 'created_at' => '2025-03-04 5:05 pm '],

        ];

        foreach ($posts as &$post) {
            if ($post['id'] == $id) {
                $post['title'] = request()->title;
                $post['description'] = request()->description;
            }
        }

        return view('posts.index', ['posts' => $posts]);
    }

    public function destroy($id)
    {

        $posts = [
            [
                'id' => 1,
                'title' => 'PHP',
                'description' => 'programmaing language',
                'posted_by' => 'Ghada',
                'created_at' => '2025-03-08 7:57 pm',
            ],
            ["id" => 2, "title" => "Laravel", 'posted_by' => 'Gehad', 'created_at' => '2025-03-04 5:05 pm '],

        ];
        foreach ($posts as $key => $post) {
            if ($post['id'] == $id) {
                unset($posts[$key]); 
                break;
            }
        }
         return view('posts.index', ['posts'=> $posts]);
    }
}
