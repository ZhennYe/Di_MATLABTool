function varargout = adimat_diff_repmat2(varargin)
   varargout{1} = 0;
   if isstruct(varargin{1})
     varargout{1} = repmat(varargin{1}, varargin{3}, varargin{4:end});
   else
     varargout{1} = repmat(varargin{1}, [1, varargin{3}, varargin{4:end}]);
   end
      ;
end
% automatically generated from $Id: derivatives-vdd.xml 3983 2013-12-21 11:20:23Z willkomm $
