<?php

namespace App\Models;
use Carbon\Carbon;
use Cviebrock\EloquentSluggable\Sluggable;
use Illuminate\Database\Eloquent\Model;
use App\Models\Comment;
use Illuminate\Support\Facades\Storage;

// Post::count();
// Post::latest()->first();

class Post extends Model
{

     use Sluggable;

    protected $fillable = [
        'title',
        'description',
        'user_id',
        'image'
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

    public function sluggable(): array
    {
        return [
            'slug' => [
                'source' => 'title',
                'onUpdate' => true, // Updates slug when title changes
                'unique' => true
            ]
        ];
    }
    public function setImageAttribute($value)
    {
        if (isset($this->attributes['image']) && $value !== $this->attributes['image']) {
            Storage::disk('public')->delete($this->attributes['image']);
        }

        $this->attributes['image'] = $value;
    }

    public function getImageAttribute()
    {
        return isset($this->attributes['image']) ? Storage::url($this->attributes['image']) : null;
    }
}
