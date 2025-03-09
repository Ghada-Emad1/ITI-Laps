@props(['type' => 'primary']) 

@php
    $baseClasses = "px-4 py-2 rounded text-white font-semibold";
    $typeClasses = match ($type) {
        'primary' => 'bg-blue-500 hover:bg-blue-600',
        'secondary' => 'bg-gray-500 hover:bg-gray-600',
        'danger' => 'bg-red-500 hover:bg-red-600',
    };
@endphp

<button class="{{ $baseClasses }} {{ $typeClasses }}">
    {{ $slot }}
</button>