
import zipfile
import xml.etree.ElementTree as ET
import os

def extract_text(docx_path):
    if os.path.exists(docx_path):
        with zipfile.ZipFile(docx_path, 'r') as zip_ref:
            if 'word/document.xml' in zip_ref.namelist():
                xml_content = zip_ref.read('word/document.xml')
                root = ET.fromstring(xml_content)
                namespace = {'w': 'http://schemas.openxmlformats.org/wordprocessingml/2006/main'}
                paragraphs = []
                for p in root.findall('.//w:p', namespace):
                    p_text = "".join([t.text for t in p.findall('.//w:t', namespace) if t.text])
                    paragraphs.append(p_text if p_text else "")
                return "\n".join(paragraphs)
    return "File not found or not a docx"

desc_p19 = r'c:\Users\Alecito\arduino-docs\otrosproy\códigospav\p19av-videojuegoStarwars'
code_p19 = r'c:\Users\Alecito\arduino-docs\otrosproy\códigospav\p19av-videojuegoStarwarscodigo'

print("--- DESCRIPTION P19 ---")
print(extract_text(desc_p19))
print("\n--- CODE P19 ---")
print(extract_text(code_p19))
