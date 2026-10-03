from Artwork import Artwork

# class Traditional Artwork
class TraditionalArtwork(Artwork):
    def __init__(self, ArtStyle, CreationDate, Price, Medium, Size):
        super().__init__(ArtStyle, CreationDate, Price)

        self.Medium = Medium
        self.Size = Size

    # Getter for class Traditional Artwork
    def getMedium(self):
        return self.Medium
    def getSize(self):
        return self.Size

    # Setter for class Traditional Artwork
    def setMedium(self, Medium):
        self.Medium = Medium
    def setSize(self, Size):
        self.Size = Size