from django.shortcuts import render, get_object_or_404
from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt
from .models import Book, Author
import json

def book_list(request):
    authors = Author.objects.all()
    return render(request, 'books/index.html', {'authors': authors})

def search_books(request):
    search_term = request.GET.get('search', '')
    if search_term:
        books = Book.objects.filter(name__icontains=search_term)
    else:
        books = Book.objects.all()

    results = []
    for book in books:
        results.append({
            'id': book.id,
            'name': book.name,
            'author': {'id': book.author.id, 'name': book.author.name},
            'publish_date': str(book.publish_date),
            'price': str(book.price),
            'appropriate_age': book.appropriate_age,
        })
    return JsonResponse({'results': results})

@csrf_exempt
def add_book(request):
    data = json.loads(request.body)
    author = get_object_or_404(Author, id=data['author_id'])

    book = Book.objects.create(
        name=data['name'],
        author=author,
        publish_date=data['publish_date'],
        price=data['price'],
        appropriate_age=data['appropriate_age'],
    )

    return JsonResponse({
        'success': True,
        'id': book.id,
        'name': book.name,
        'author': {'id': author.id, 'name': author.name},
        'publish_date': str(book.publish_date),
        'price': str(book.price),
        'appropriate_age': book.appropriate_age,
    })

@csrf_exempt
def edit_book(request, book_id):
    data = json.loads(request.body)
    book = get_object_or_404(Book, id=book_id)
    author = get_object_or_404(Author, id=data['author_id'])

    book.name = data['name']
    book.author = author
    book.publish_date = data['publish_date']
    book.price = data['price']
    book.appropriate_age = data['appropriate_age']
    book.save()

    return JsonResponse({
        'success': True,
        'id': book.id,
        'name': book.name,
        'author': {'id': author.id, 'name': author.name},
        'publish_date': str(book.publish_date),
        'price': str(book.price),
        'appropriate_age': book.appropriate_age,
    })

@csrf_exempt
def delete_book(request, book_id):
    book = get_object_or_404(Book, id=book_id)
    book.delete()
    return JsonResponse({'success': True})
