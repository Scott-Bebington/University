from django.shortcuts import render

# Create your views here.

def stats(request):
    data = {
    'success': True,
    'message': "Hello Word!",
    }
    return render(request, 'home/index.html', data)