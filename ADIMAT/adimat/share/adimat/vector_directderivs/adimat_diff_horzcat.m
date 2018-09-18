function varargout = adimat_diff_horzcat(varargin)
   varargout{2} = horzcat(varargin{2:2:end});
   if iscell(varargin{2}) || isstruct(varargin{2})
      varargout{1} = horzcat(varargin{1:2:end});
   else
      varargout{1} = cat(3, varargin{1:2:end});
   end

end
% automatically generated from $Id: derivatives-vdd.xml 3983 2013-12-21 11:20:23Z willkomm $
