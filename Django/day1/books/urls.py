from django.urls import path
from . import views

app_name = 'books'
urlpatterns = [
    path('', views.index, name='index'),
    path('<int:book_id>/', views.book_details, name='book_details'),
    path('authors/<int:author_id>/',views.author,name='author')
]