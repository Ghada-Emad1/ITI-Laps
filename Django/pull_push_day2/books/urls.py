from django.urls import path
from . import views

urlpatterns = [
    path('', views.book_list, name='book_list'),
    path('search/', views.search_books, name='search_books'),
    path('add/', views.add_book, name='add_book'),
    path('edit/<int:book_id>/', views.edit_book, name='edit_book'),
    path('delete/<int:book_id>/', views.delete_book, name='delete_book'),
]
