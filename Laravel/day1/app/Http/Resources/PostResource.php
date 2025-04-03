<?php

namespace App\Http\Resources;

use Illuminate\Http\Request;
use Illuminate\Http\Resources\Json\JsonResource;

class PostResource extends JsonResource
{
    /**
     * Transform the resource into an array.
     *
     * @return array<string, mixed>
     */
    public function toArray(Request $request): array
    {
        // return parent::toArray($request);
        return [
            'id' => $this->id,
            'title' => $this->title,
            'description' => $this->description,
            'created_at' => $this->created_at,
            'image' => $this->image ? asset('storage/' . $this->image) : null,
            // 'user'=>$this->user?[
            //     'id'=>$this->user->id,
            //     'name'=>$this->user->name,
            //     'email'=>$this->user->email
            // ]:null,
            'user'=>new UserResource($this->user),
        ];
    }
}
