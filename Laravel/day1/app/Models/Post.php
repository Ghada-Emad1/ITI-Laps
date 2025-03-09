<?php

namespace App\Models;
use Carbon\Carbon;
use Illuminate\Database\Eloquent\Model;
use App\Models\Comment;
Post::count();
Post::latest()->first();

class Post extends Model
{



    protected $fillable = [
        'title',
        'description',
        'user_id',
    ];

    public function user()
    {
        return $this->belongsTo(User::class);
    }

    public function getFormattedCreatedAtAttribute()
    {
        return Carbon::parse($this->created_at)->format('d M Y, h:i A');
    }

    // public function postCreator()
    // {
    //     return $this->belongsTo(User::class, 'user_id');
    // }

    public function comments()
    {
        return $this->morphMany(Comment::class, 'commentable');
    }
}
