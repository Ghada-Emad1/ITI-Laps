<?php

namespace App\Http\Requests;

use Illuminate\Foundation\Http\FormRequest;

class StorePostRequest extends FormRequest
{
    /**
     * Determine if the user is authorized to make this request.
     */
    public function authorize(): bool
    {
        return true;
    }

    /**
     * Get the validation rules that apply to the request.
     *
     * @return array<string, \Illuminate\Contracts\Validation\ValidationRule|array<mixed>|string>
     */
    public function rules(): array
    {
        return [
            'title'=>['required','min:3','unique:posts,title'],
            'description'=>['required','min:10'],
            'user_id'=>['required','exists:users,id'],
            'image'=>['nullable','image','mimes:jpg,png','max:2048']
        ];
    }
    public function messages(): array
    {
        return [
            'title.required' => 'A title is required.',
            'title.min' => 'The title must be at least 3 characters.',
            'title.unique' => 'This title has already been taken.',
            'description.required' => 'A description is required.',
            'description.min' => 'The description must be at least 10 characters.',
            'user_id.required' => 'A user ID is required.',
            'user_id.exists' => 'The user ID does not exist in the database.',
            'image.required'=>'Please Upload a valid image',
            'image.image' => 'The file must be an image.',
            'image.mimes' => 'The image must be a file of type: jpg, png.',
            'image.max' => 'The image size must not exceed 2MB.',
        ];
    }
}
