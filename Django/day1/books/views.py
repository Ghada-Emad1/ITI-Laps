from django.shortcuts import render
import json  # Import the json module

from .models import Book,Author
# Create your views here.

# def read_book():
#     with open("books.json", "r") as file:
#         books = json.load(file)  
#         return books

def index(request):
    books=Book.objects.all()
    print(books)
    return render(request, "books/index.html", {"books": books})

def book_details(request,book_id):
    book=Book.objects.all().select_related('author').get(id=book_id)
    return render(request, "books/book_details.html", {"book": book})

def author(request,author_id):
    author=Author.objects.get(id=author_id)
    return render(request,"books/author.html",{"author":author})
   
