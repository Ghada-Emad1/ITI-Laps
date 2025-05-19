from django.db import models

# Create your models here.

class Book(models.Model):
    name=models.CharField(max_length=100)
    publish_date=models.DateField()
    add_to_site_at=models.DateTimeField(auto_now_add=True)
    #author is linked to the author table
    author=models.ForeignKey('Author',on_delete=models.CASCADE)
    price=models.DecimalField(max_digits=10,decimal_places=2)
    appropriate_age=models.CharField(max_length=100,
    choices=[
        
        ('age between 0-8','0-8'),
        ('age between 8-15','8-15'),
        ('age greater than 18','adult'),
    ])

class Author(models.Model):
    name=models.CharField(max_length=100)
    