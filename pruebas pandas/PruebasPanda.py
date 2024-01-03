#pip install PyMuPDF pytesseract reportlab
#https://github.com/tesseract-ocr/tesseract
#pip install Pillow
#pip install openpyxl
#pip install pandas
import fitz  # PyMuPDF
from PIL import Image
import pytesseract
import io
import os
import re
import pandas as pd


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
    informacion_extraccion = []

    for img in imagenes:
        texto = pytesseract.image_to_string(img, lang='eng')

        # Utilizar expresiones regulares para buscar el número del DECRETO EXENTO y la fecha
        patron_decreto = r'DECRETO EXENTO N° (\d+)'
        patron_fecha = r'(\d+ de \w+ del \d+)'

        numero_decreto = re.search(patron_decreto, texto)
        fecha_match = re.search(patron_fecha, texto)

        # Extraer la información y agregarla a la lista
        if numero_decreto:
            numero_decreto = numero_decreto.group(1)
        else:
            numero_decreto = None

        if fecha_match:
            fecha = fecha_match.group(0)
        else:
            fecha = None

        informacion_extraccion.append({
            'numero_decreto': numero_decreto,
            'fecha': fecha
        })

    return informacion_extraccion

# Ruta de la carpeta que contiene los archivos PDF
carpeta_pdf = r'C:\Users\benja\Desktop\Pruebas'

# Lista para almacenar la información extraída de todos los PDFs
informacion_total = []

# Iterar sobre todos los archivos PDF en la carpeta
for archivo_pdf in os.listdir(carpeta_pdf):
    if archivo_pdf.endswith('.pdf'):
        # Construir la ruta completa del archivo PDF
        pdf_path = os.path.join(carpeta_pdf, archivo_pdf)

        # Extraer imágenes desde el PDF
        imagenes_pdf = extraer_imagenes_desde_pdf(pdf_path)

        # Realizar OCR en las imágenes
        informacion_extraccion = realizar_ocr_en_imagenes(imagenes_pdf)

        # Agregar la información al total
        informacion_total.extend(informacion_extraccion)

# Crear un DataFrame con la información total
df = pd.DataFrame(informacion_total)

# Exportar el DataFrame a un archivo Excel
excel_path = r'C:\Users\benja\Desktop\Pruebas\informacion_extraida.xlsx'
df.to_excel(excel_path, index=False)

print(f"La información se ha exportado correctamente a '{excel_path}'")


