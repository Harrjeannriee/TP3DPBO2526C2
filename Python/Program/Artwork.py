# Artwork
class Artwork:
    def __init__(self, ArtStyle, CreationDate, Price):
        self.ArtStyle = ArtStyle
        self.CreationDate = CreationDate
        self.Price = Price

    # Getter for class Artwork
    def getArtStyle(self):
        return self.ArtStyle
    def getCreationDate(self):
        return self.CreationDate
    def getPrice(self):
        return self.Price

    # Setter for class Artwork
    def setArtStyle(self, ArtStyle):
        self.ArtStyle = ArtStyle
    def setCreationDate(self, CreationDate):
        self.CreationDate = CreationDate
    def setPrice(self, Price):
        self.Price = Price