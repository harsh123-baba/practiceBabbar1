import os , shutil

dict_extensions = {

    'audio_extensions' : ('.mp3', '.m4a', '.flac', '.wav', '.wlac', '.aac'),
    'video_extensions' : ('.mp4', '.webm', '.mpg', '.mp2', '.mpeg', '.mpe', '.mpv', '.avi', '.mkv'),
    'document_extensions' : ('.txt', '.pdf', '.docx'),
}



folderPath = input("Enter folder path : ")

def file_finder(folderPath, file_extension):
    File = []
    for file in os.listdir(folderPath):
        for extension in file_extension:
            if file.endswith(extension):
                File.append(file)
    return File

# print(file_finder(folderPath, audio_extensions))

for extension_type, extension_tuple in dict_extensions.items():
    
    for item in file_finder(folderPath, extension_tuple):
        if(len(item) != 0):
            folder_name = extension_type.split('_')[0] + 'Files'
            folder_path = os.path.join(folderPath, folder_name)
            if os.path.exists(folder_path):
                item_path = os.path.join(folderPath, item);
                item_new_path = os.path.join(folder_path, item);
                shutil.move(item_path, item_new_path);
            else:

                os.mkdir(folder_path)        
                item_path = os.path.join(folderPath, item);
                item_new_path = os.path.join(folder_path, item);
                shutil.move(item_path, item_new_path);




