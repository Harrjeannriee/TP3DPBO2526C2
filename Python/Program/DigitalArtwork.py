from Artwork import Artwork

# Class Digital Artwork
class DigitalArtwork(Artwork):
    def __init__(self, ArtStyle, CreationDate, Price, Resolution, FileFormat):
        super().__init__(ArtStyle, CreationDate, Price)

        self.Resolution = Resolution
        self.FileFormat = FileFormat

    # Getter for class Digital Artwork
    def getResolution(self):
        return self.Resolution
    def getFileFormat(self):
        return self.FileFormat

    # Setter for class Digital Artwork
    def setResolution(self, Resolution):
        self.Resolution = Resolution
    def setFileFormat(self, FileFormat):
        self.FileFormat = FileFormat