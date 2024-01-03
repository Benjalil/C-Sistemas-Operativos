#pip install PyMuPDF pytesseract reportlab
#https://github.com/tesseract-ocr/tesseract
#pip install Pillow

import fitz  # PyMuPDF
from PIL import Image
import pytesseract
import io
import os

# Configura la ruta al ejecutable de Tesseract-OCR (puedes omitir esto si está en tu PATH)
pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract.exe'

def extraer_imagenes_desde_pdf(pdf_path):
    imagenes = []

    with fitz.open(pdf_path) as pdf_document:
        for pagina_num in range(pdf_document.page_count):
            pagina = pdf_document[pagina_num]
            imagenes_pagina = pagina.get_images(full=True)

            for img_indice, img_info in enumerate(imagenes_pagina):
                xref = img_info[0]
                base_imagen = pdf_document.extract_image(xref)
                imagen_bytes = base_imagen["image"]
                imagen_pil = Image.open(io.BytesIO(imagen_bytes))
                imagenes.append(imagen_pil)

    return imagenes

def realizar_ocr_en_imagenes(imagenes):
    texto_reconocido = []

    for img in imagenes:
        texto = pytesseract.image_to_string(img, lang='eng')
        texto_reconocido.append(texto)

    return texto_reconocido

# Ruta de la carpeta que contiene los archivos PDF
carpeta_pdf = r'C:\Users\benja\Desktop\Pruebas'

# Iterar sobre todos los archivos PDF en la carpeta
for archivo_pdf in os.listdir(carpeta_pdf):
    if archivo_pdf.endswith('.pdf'):
        # Construir la ruta completa del archivo PDF
        pdf_path = os.path.join(carpeta_pdf, archivo_pdf)

        # Extraer imágenes desde el PDF
        imagenes_pdf = extraer_imagenes_desde_pdf(pdf_path)

        # Realizar OCR en las imágenes
        texto_reconocido = realizar_ocr_en_imagenes(imagenes_pdf)

        # Imprimir el texto reconocido
        for i, texto in enumerate(texto_reconocido):
            print(f"Texto en la página {i + 1} del archivo {archivo_pdf}:\n{texto}")
